n=int(input())
st=0
co=0
ind=-1
tot=0
tot2=0
s=list(input())
for i in range(n):
    if(s[i]=="("):
        tot2+=1
    if st==0:
        if(s[i]=="("):
            
            co+=1
        else:
            co-=1
        if(co<0):
            st=1
            ind=i
    else:
        if(s[i]=="("):
            co+=1
        else:
            co-=1
        if(co==0):
            tot+=i-ind+1
            st=0
if tot2==n-tot2:
    print(tot)
else:
    print(-1)