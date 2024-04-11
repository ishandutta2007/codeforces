import sys
input=sys.stdin.readline
t=int(input())
p=[]
for _ in range(t):
    n=int(input())
    
    fac=[]
    for i in range(2,int(n**0.5)+1):
        if(n%i==0):
            fac.append(i)
            fac.append(n//i)
    
    nn=len(fac)
    st=0
   # print(fac)
    for i in range(nn):
        for j in range(i+1,nn):
            if(n%(fac[i]*fac[j])==0):
                k=n//(fac[i]*fac[j])
                if fac[i]==fac[j] or fac[i]==k or fac[j]==k:
                    continue
                if 1 in [fac[i],fac[j],k]:
                    continue
                st=1
                ii,jj,kk=fac[i],fac[j],k
                break
            
    if st:
        print("YES")
        print(ii,jj,kk)
    else:
        print("NO")