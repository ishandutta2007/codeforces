from functools import *
from math import *
from random import *
i,p=input,print
n=int(i())
f={n}
for _ in range(15):x=randint(1,n-1);p('sqrt',(x*x)%n);x+=int(i());f=set(reduce(list.__add__,[[gcd(x,a),a//gcd(x,a)]for a in f]))-{1}
p('!',len(f),*f)