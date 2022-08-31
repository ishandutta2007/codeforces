def rec(ind,cc=1,dd=1):
    global pp,a,b
    if ind==len(pp):
        if max(cc,dd)<max(a,b):
            a,b=cc,dd
        return
    rec(ind+1,cc*pp[ind],dd)
    rec(ind+1,cc,dd*pp[ind])
x=int(input())
p=[]
vis=[0 for i in range(10**6+4)]
vis[0]=1
vis[1]=1
for i in range(2,10**6+4):
    if vis[i]==0:
        p.append(i)
        vis[i::i]=len(vis[i::i])*[1]

    
pp=[]
ind=0
xx=x
while xx>1 and ind<len(p):
    co=1
    while xx%p[ind]==0:
        xx//=p[ind]
        co*=p[ind]
    ind+=1
    if co==1:
        continue
    pp.append(co)
        

if xx>1:
    pod=1
    for i in pp:
        pod*=i
    print(xx,pod)
elif x==1:
    print(1,1)
else:
    
    a=1
    b=x
    rec(0)
    print(a,b)