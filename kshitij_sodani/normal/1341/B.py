#list(map(int,input().split()))
t=int(input())
for _ in range(t):
    n,k=map(int,input().split())
    aa=list(map(int,input().split()))
    tot=0
    ind=1
    
    for i in range(1,k-1):
        if(aa[i]>aa[i-1] and aa[i]>aa[i+1]):
            tot+=1
  #  print(tot)
    ma=tot+1
    for i in range(1,n):
        if(i+k-1>=n):
            continue
        if(aa[i]>aa[i-1] and aa[i]>aa[i+1]):
            tot-=1
        if(aa[i+k-2]>aa[i+k-3] and aa[i+k-2]>aa[i+k-1]):
            tot+=1
        if(tot+1>ma):
            ma=tot+1
            ind=i+1
      #  print(tot)
    print(ma,ind)