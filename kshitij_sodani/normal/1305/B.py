s=input()
n=len(s)
pre=[0 for i in range(n)]
if s[n-1]==")":
    pre[n-1]=1
for i in range(n-2,-1,-1):
    if s[i]==")":
        pre[i]=pre[i+1]+1
    else:
        pre[i]=pre[i+1]
co=0
aa=[]
for i in range(n):
    if(s[i]=="("):
        co+=1
        if(pre[i]<co):
            co-=1
            break
        else:
            aa.append(i+1)
            ind=i
if aa==[]:
    print(0)
else:
    print(1)
    print(len(aa)*2)
    for i in range(n-1,ind,-1):
        if co==0:
            break
        if s[i]==")":
            aa.append(i+1)
            co-=1
    aa.sort()
    print(*aa)