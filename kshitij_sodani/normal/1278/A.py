t=int(input())
for _ in range(t):
    p=input()
    h=input()
    ans="NO"
    n=len(h)
    ss={}
    tt={}
    for i in range(min(len(p),len(h))):
        try:
            ss[h[i]]+=1
            
        except:
            ss[h[i]]=1
    for i in range(len(p)):
        try:
            tt[p[i]]+=1
        except:

            tt[p[i]]=1
    if ss==tt:
        ans="YES"
   # print(ss)
    for i in range(1,n-len(p)+1):
        ss[h[i-1]]-=1
        if ss[h[i-1]]==0:
            del ss[h[i-1]]
        try:
            ss[h[i+len(p)-1]]+=1
        except:
            ss[h[i+len(p)-1]]=1
        
        if ss==tt:
            ans="YES"
    print(ans)