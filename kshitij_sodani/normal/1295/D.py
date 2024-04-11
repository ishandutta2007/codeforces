import sys
input=sys.stdin.readline
from math import gcd
from itertools import combinations as cc
t=int(input())
def rec(ind,prod,co=0):
    global tot
    if ind==len(fac):
        if prod==1:
            return 
        if co%2==1:
            tot+=(r)//prod-(l-1)//prod
        else:
            tot-=(r//prod-(l-1)//prod)
    else:
        rec(ind+1,prod,co)
        rec(ind+1,prod*fac[ind],co+1)
for _ in range(t):
    a,m=map(int,input().split())
    tot=0
    x=gcd(a,m)
    m//=x
    a//=x
    l=a
    r=a+m-1
    fac=[]
    for i in range(1,int(m**0.5)+2):
        if m%i==0:
            if i!=1:
                
                st=1
                for j in range(2,min(int(i**0.5)+2,i)):
                    if i%j==0:
                        st=2
                        break
                if st==1:
                    fac.append(i)
            i=m//i
            if i!=1:
                st=1
                for j in range(2,min(int(i**0.5)+2,i)):
                    if i%j==0:
                        st=2
                        break
                if st==1:
                    fac.append(i)
    
    fac=list(set(fac))
    #print(fac)
    rec(0,1,0)
    #print(tot)
    print(m-tot)