def exgcd(a,b):
    if b==0:
        return 1,0
    x,y=exgcd(b,a%b)
    return y,x-y*(a//b)
def inv(a,p):
    x,y=exgcd(a,p)
    return (x%p+p)%p
def xmul(a,b):
    c=[[0,0],[0,0]]
    for i in range(0,2):
        for j in range(0,2):
            for k in range(0,2):
                c[i][j]=(c[i][j]+a[i][k]*b[k][j])%(10**12)
    return c
def xpow(a,b):
    s=[[1,0],[0,1]]
    while b:
        if b%2:
            s=xmul(s,a)
        a=xmul(a,a)
        b//=2
    return s
def fib(n):
    if n<=1:
        return n
    return xmul([[1,0],[0,0]],xpow([[1,1],[1,0]],n-1))[0][0]
if __name__=="__main__":
    t=fib(3*(10**6)+1)//(10**6)
    u=15*inv(t//2,10**6)
    n,a,d=map(int,input().split())
    b=a*u*(10**6)+1
    e=d*u*(10**6)
    print(b,e)