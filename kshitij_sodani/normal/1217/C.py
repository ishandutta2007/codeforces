from math import log
t=int(input())
aa=[1]
for i in range(100):
    aa.append(aa[-1]*2)
for _ in range(t):
    s=input()
    ii=[]
    co=0
    j=0
    ss={}
    ind=-1
    for i in s:
        if i=="0":
            if ind==-1:
                ind=j
            co+=1
        else:
            if ind!=-1:
                ss[j-1]=ind
            co=0
            ind=-1
        j+=1
    if s[-1]=="0":
        ss[len(s)-1]=ind
    ans=0
    for i in range(1,int(log(len(s))/log(2))+2):
        for j in range(len(s)-i+1):
            st=s[j:j+i]
            if st[0]=="1":
                tot=0
                for ii in range(i):
                    if st[-ii-1]=="1":
                      #  print(ii)
                        tot+=aa[ii]
                le=tot-i
                try:
                    xx=ss[j-1]
                    if (j-xx)>=le:
                        ans+=1
                     #   print(i,j,tot,st)
                except:
                    if le==0:
                        ans+=1
                    #    print(i,j,tot,st)
                    pass
    print(ans)
 #   print()