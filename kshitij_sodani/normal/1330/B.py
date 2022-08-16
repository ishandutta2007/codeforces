import sys
input=sys.stdin.readline
t=int(input())
for _ in range(t):
    n=int(input())
    aa=list(map(int,input().split()))
    ss=set()
    
    st=0
    ind=1
    pre=[0 for i in range(n)]
    for i in range(n):
        if aa[i] in ss:
            break
        ss.add(aa[i])
        while ind<=len(ss):
            if ind in ss:
                ind+=1
            else:
                break
        if len(ss)!=ind-1:
            pre[i]=0
        else:
            pre[i]=ind
    ind=1
   # print(pre)
    ss=set()
    suff=[0 for i in range(n)]
    for i in range(n-1,-1,-1):
        if aa[i] in ss:
            break
        ss.add(aa[i])
        while ind<=len(ss):
            if ind in ss:
                ind+=1
            else:
                break
        if len(ss)!=ind-1:
            suff[i]=0
        else:
            suff[i]=ind
    tot=0
    ans=[]
    for i in range(n-1):
        if pre[i]>0 and suff[i+1]>0:
            tot+=1
            ans.append([i+1,n-i-1])
    print(tot)
    for i in ans:
        print(i[0],i[1])