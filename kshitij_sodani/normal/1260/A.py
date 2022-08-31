n=int(input())
for i in range(n):
    a,b=map(int,input().split())
    if b<a:
        print(b)
        continue
    else:
        ss=b//a
        tt=b%a
        tot=0
        tot+=a*(ss**2)
        tot+=tt*(ss+ss+1)
        print(tot)