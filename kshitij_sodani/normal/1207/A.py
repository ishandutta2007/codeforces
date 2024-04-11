t=int(input())
for _ in range(t):
    b,p,f=map(int,input().split())
    h,c=map(int,input().split())
    mi=0
    for i in range(b//2+1):
        tot=0
        bb=min(p,i)
        tot+=bb*h
        cc=min((b-i*2)//2,f)
        tot+=cc*c
        mi=max(mi,tot)
    print(mi)