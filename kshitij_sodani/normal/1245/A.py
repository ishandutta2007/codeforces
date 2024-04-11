def gcd(a,b):
    if b==0:
        return a
    return gcd(b,a%b)
t=int(input())
for _ in range(t):
    a,b=map(int,input().split())
    c=gcd(a,b)
    if c==1:
        print("Finite")
    else:
        print("Infinite")