import sys
input=sys.stdin.readline
n,k=map(int,input().split())
#sys.stdout.flush()
x=sys.stdout.flush
if k==1:
    print("!",1)
    x()
else:
    vis=[0 for i in range(n)]
    arr=[i+1 for i in range(n)]
    st=1
    mi=-1
    mi_ind=1
    ma=float("inf")
    ma_inf=1
    for i in range(n-k+1):
        arr=[i+1 for i in range(n) if vis[i]==0][:k]
        print("?",*arr)
        x()
        try:
            ind,val=map(int,input().split())
            vis[ind-1]=1
            if val>mi:
                mi=val
                mi_ind=ind
            if val<ma:
                ma=val
                ma_ind=ind
        except:
            st=0
            break
    if st:
        do=[i+1 for i in range(n) if vis[i]==0]
        stt=[]
        do.append(ma_ind)
        do.append(mi_ind)
      #  print(do)
        co=k-1
        for i in range(k-1):
            dd=[do[j] for j in range(k+1) if do[j]!=do[i]]
            print("?",*dd)
            x()
            ind,val=map(int,input().split())
          #  print(11)
            if val==ma:
                co-=1
              #  print(dd[:-1])
        print("!",co+1)
        x()