n=int(input())
it=list(map(int,input().split()))
aa=list(map(int,input().split()))
ss={}
for i in range(n):
    ss[it[i]]=i
aa=[ss[i] for i in aa]
ma=n+1
tot=0
d=[0]*n
mi=0
for i in range(n):
    if aa[i]>mi:
        tot+=1
    d[aa[i]]=1
    
    if mi==aa[i]:
        while mi<n:
            if d[mi]==1:
                mi+=1
            else:
                break
        
print(tot)