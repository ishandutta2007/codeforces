import sys
input=sys.stdin.readline
t=int(input())
for _ in range(t):
    n,s=map(int,input().split())
    it=list(map(int,input().split()))
    ma=0
    ind=0
    tot=0
    ans=0
    ma_ind=0
    for i in range(n):
        tot+=it[i]
        #print(tot)
        if tot<=s:
            if i+1>ans:
                
                ind=0
                
            ans=max(ans,i+1)
            
        else:
            if tot-ma<=s:
                if i>ans:
                    ind=ma_ind
                ans=max(ans,i)
        if it[i]>ma:
            ma_ind=i+1
        ma=max(ma,it[i])
       # print(ans,ma,ind,ma_ind)
    print(ind)