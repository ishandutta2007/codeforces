#!/usr/bin/env python3
# -*- coding: utf-8 -*-
__author__ = 'QAQAutoMaton'
import sys
n,k=map(int,input().split())
def ask(w):
    s='?'
    for i in range(1,k+2):
        if i!=w:
            s+=' '+str(i)
    print(s)
    sys.stdout.flush()
    return map(int,input().split())
 
x,y=ask(k+1)
 
x2,y2=ask(x)
 
if(y>y2):
	t=x
	x=x2
	x2=t
 
ans=1
for i in range(1,k+2):
    if(i!=x and i!=x2):
        a,b=ask(i)
        if(a==x2):
            ans+=1
print('!',ans)
sys.stdout.flush()