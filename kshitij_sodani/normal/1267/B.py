s=input()
tt=[[0,0]]
n=len(s)
for i in range(1,n):
    if s[i]==s[tt[-1][1]]:
        tt[-1][1]+=1
    else:
        tt.append([i,i])
n=len(tt)
ss=tt[:]
tt=[i[1]-i[0]+1 for i in tt]
if len(tt)%2==1:
    if tt[n//2]+1>=3:
        st=True
        for i in range(n//2):
            if tt[i]+tt[n-i-1]<3 or s[ss[i][0]]!=s[ss[n-i-1][1]]:
                st=False
        if st:
            print(tt[n//2]+1)
        else:
            print(0)
    else:
        print(0)
else:
    print(0)