import bisect as bs
t=int(input())
it=list(map(int,input().split()))
tt=[]
s={}
for i in it:
    try:
        s[abs(i)]+=1
    except:
        s[abs(i)]=1
        tt.append(abs(i))
tt.sort()
aa=[s[tt[0]]]
su=0
for i in tt[1:]:
    aa.append(aa[-1]+s[i])
for i in range(len(tt)):
    k=tt[i]
    ind=bs.bisect_left(tt,2*k+1)
    su+=(aa[ind-1]-aa[i])*s[k]+(s[k]-1)
print(su)