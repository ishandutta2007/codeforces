it=list(map(int,input().split()))
ll=min(it[0],it[1])
it[0]-=ll
it[1]-=ll
k=it[0]>0
l=it[1]>0
n=it[2]*2
n+=ll*2
if k:
    n+=1
if l:
    n+=1
print(n)