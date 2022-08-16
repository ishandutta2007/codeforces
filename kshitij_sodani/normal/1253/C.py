n,m=map(int,input().split())
it=list(map(int,input().split()))
if n==1:
    print(it[0])
else:
    it.sort()
    tot=0
    cu=0
    d=1
    fi=it[0]
    aa=[0 for i in range(m)]
    tt=[]
    for i in range(n):

            
        tot+=aa[(i-(m-1))%m]
       # tot+=it[i]
        aa[i%m]+=it[i]
        if tot!=0 and tt[-1]==0:
            ind=i
        tt.append(tot)
        
      #  print(tot,end=" ")
    for i in range(n,n+ind):
        tt.append(tt[-1]+aa[(i-(m-1))%m])
    #tot+=aa[(n-(m-1))%m]

    print(*tt[ind:])