import sys
input=sys.stdin.readline
t=int(input())
for _ in range(t):
    n=int(input())
    it=list(map(int,input().split()))
    mi=it[0]
    ma=it[0]
    st=0
    for i in range(n-1):
        if abs(it[i]-it[i+1])>=2:
            st=1
            ans=i
            break
    if st:
        print("YES")
        print(ans+1,ans+2)
    else:
        print("NO")