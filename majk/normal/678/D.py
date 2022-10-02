m=1000000007

def mult(A,B):
    global m
    return (
        ((A[0][0]*B[0][0]+A[0][1]*B[1][0])%m,
        (A[0][0]*B[0][1]+A[0][1]*B[1][1])%m),
        ((A[1][0]*B[0][0]+A[1][1]*B[1][0])%m,
        (A[1][0]*B[0][1]+A[1][1]*B[1][1])%m)
    )

a,b,n,x=map(int,input().split())
mat,res=((a,b),(0,1)),((1,0),(0,1))
while n:
    if n % 2:
        res = mult(res,mat)
    mat = mult(mat,mat)
    n //= 2

print((res[0][0]*x + res[0][1]) % m)