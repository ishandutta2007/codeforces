q = int(input())
while q>0:
    q=q-1
    n=int(input())
    A=list(map(int, input().split()))
    A.sort()
    #print(A)
    ans=1
    if n==1:
        print(1)
    else:
        for i in range(1, n):
            if A[i]==A[i-1]+1:
                ans=2
        print(ans)