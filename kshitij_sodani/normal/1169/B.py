n,m=map(int,input().split())
s={}
st=False
for i in range(m):
    x,y=map(int,input().split())
    if i==0:
        xx=x
        yy=y
    elif st==False:
        if yy not in [x,y] and xx not in [x,y]:
            xx2=x
            yy2=y
            st=True
    try:
        s[x].add(i)
    except:
        s[x]=set([i])
    try:
        s[y].add(i)
    except:
        s[y]=set([i])
stt="NO"
k=set(list(range(0,m)))
arr=[xx,yy]
if st:
    arr.extend([xx2,yy2])
for i in arr:
    if len(s[i])>=m/2:
        for ii in arr:
            if i==ii:
                continue
            if len(s[ii])>=m-len(s[i]):
                if s[ii].union(s[i])==k:
                    stt="YES"
                    break

print(stt)