n=int(input())
aa=[]
bb=[]
for _ in range(n):
    aa.append(list(map(int,input().split())))
m=int(input())
for _ in range(m):
    bb.append(list(map(int,input().split())))
x=min(aa,key=lambda x:x[1])
y=max(bb,key=lambda x:x[0])
mi=max(y[0]-x[1],0)
x=min(bb,key=lambda x:x[1])
y=max(aa,key=lambda x:x[0])
mi=max(mi,max(y[0]-x[1],0))
print(mi)