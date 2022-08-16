n=int(input())
s=[-1]*n
ind=1
cu=1
while ind<n:
    if s[ind]==-1:
        s[ind::ind+1]=len(s[ind::ind+1])*[cu]
        cu+=1
    ind+=1
for i in s[1:]:
    print(i,end=" ")
print()