import sys
input=sys.stdin.readline
t=int(input())
for _ in range(t):
    n,x=map(int,input().split())
    it=list(map(int,input().split()))
    tt=set(it)
    tot=0
    xx=x
    y=max(it)
    tot=xx//y
    yy=xx%y
    if x in it:
        print(1)
        continue
    if y>x:
        print(2)
        continue
    if yy==0:
        print(tot)
        continue
    tot+=1

    print(tot)