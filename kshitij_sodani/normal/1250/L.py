t=int(input())
for _ in range(t):
    a,b,c=map(int,input().split())
    a,b,c=sorted([a,b,c])
    aa=a
    bb=b
    cc=c
    d=c-b
    c-=min(d,a)
    a-=min(a,d)
    b-=min(a//2,0)
    a-=min(a//2,0)
    c-=min(a,0)
    a-=min(a,0)
    b,c=sorted([b,c])
    c-=b
    b=0
    print((aa+bb+cc-c)//2)