/*
 * Copyright 2005 Vinzenz Feenstra - evilissimo@users.sourceforge.net
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */
#ifndef GUARD_DELGATES_DELEGATE6_HPP_INCLUDED
#define GUARD_DELGATES_DELEGATE6_HPP_INCLUDED 1

#include "DelegateBase.hpp"

namespace DL 
  {
  /** Delegate for 6 Param
  *
  */
  template < class ReturnType , 
    class ClassType  , 
    class Param1     ,
    class Param2     ,
    class Param3     ,
    class Param4     ,
    class Param5     ,
    class Param6     
    >
  class Delegate6 : public DelegateBase 
  {
  ClassType* m_class_obj;
  ReturnType (ClassType::*m_method)(Param1,Param2,Param3,Param4,Param5,Param6);
  Param1 m_val1;
  Param2 m_val2;
  Param3 m_val3;
  Param4 m_val4;
  Param5 m_val5;
  Param6 m_val6;
  Delegate6(){}
  public:
  Delegate6(ClassType* class_obj,
    ReturnType (ClassType::*method)(Param1,Param2,Param3,Param4,Param5,Param6),
    Param1 val1 = Param1(),
    Param2 val2 = Param2(),
    Param3 val3 = Param3(),
    Param4 val4 = Param4(),
    Param5 val5 = Param5(),
    Param6 val6 = Param6()):
    m_class_obj(class_obj), m_method(method),
    m_val1(val1),m_val2(val2),m_val3(val3),
    m_val4(val4),m_val5(val5),m_val6(val6)
    {}
  virtual ~Delegate6(){}
  void operator()()
  {
  (*m_class_obj.*m_method)(m_val1,m_val2,m_val3,m_val4,m_val5,m_val6);
  }
  ReturnType operator()(Param1 val1,Param2 val2,Param3 val3,Param4 val4,Param5 val5,Param6 val6)
  {
    return (*m_class_obj.*m_method)(val1,val2,val3,val4,val5,val6);
  }
  void Invoke()
  {
  (*m_class_obj.*m_method)(m_val1,m_val2,m_val3,m_val4,m_val5,m_val6);
  }
  ReturnType Invoke(Param1 val1,Param2 val2,Param3 val3,Param4 val4,Param5 val5,Param6 val6)
  {
    return (*m_class_obj.*m_method)(val1,val2,val3,val4,val5,val6);
  }
  };
  
  //######################################################################################################
  template < class ReturnType , class ClassType , class Param1  , 
             class Param2     , class Param3    , class Param4  , 
       class Param5     , class Param6    
     >
  DelegateObj create_delegate( ClassType & obj , ReturnType(ClassType::*Meth)(Param1,Param2,Param3,Param4,Param5,Param6), 
                Param1 & param1 , Param2 & param2 , Param3 & param3 ,
                Param4 & param4 , Param5 & param5 , Param6 & param6 )
  {
  return DelegateObj(new Delegate6<ReturnType,ClassType,Param1,Param2,Param3,Param4,Param5,Param6>
    (&obj,Meth,param1,param2,param3,param4,param5,param6));
  }
  
  template < class ReturnType , class ClassType , class Param1  , 
             class Param2     , class Param3    , class Param4  , 
       class Param5     , class Param6    
     >
  DelegateObj create_delegate( ClassType * obj , ReturnType(ClassType::*Meth)(Param1,Param2,Param3,Param4,Param5,Param6), 
                Param1 & param1 , Param2 & param2 , Param3 & param3 ,
                Param4 & param4 , Param5 & param5 , Param6 & param6 )
  {
  return DelegateObj(new Delegate6<ReturnType,ClassType,Param1,Param2,Param3,Param4,Param5,Param6>
    (obj,Meth,param1,param2,param3,param4,param5,param6));
  }
  
} // namespace DL
#endif // GUARD_DELGATES_DELEGATE6_HPP_INCLUDED
