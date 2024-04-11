import sys
input=sys.stdin.readline
n,m=map(int,input().split())
aa=list(map(int,input().split()))
if sum(aa)<n:
    print(-1)
else:
    ans=[0 for i in range(m)]
    for i in range(m):
        ans[i]=i
            
    if(i+aa[-1]-1>=n):
        print(-1)
    else:
        tot=(n-1)-(ans[m-1]+aa[m-1]-1)
        tot2=0
        ans[-1]=n-1-aa[m-1]+1
       # print(tot,ans)
        for i in range(m-2,-1,-1):
            if(ans[i]+aa[i]<ans[i+1]):
                ans[i]+=ans[i+1]-(ans[i]+aa[i])
        
        st=1
        for i in range(m):
            if n-ans[i]<aa[i]:
                st=0
        if st==0:
            print(-1)
        else:
            print(*([ans[i]+1 for i in range(m)]))