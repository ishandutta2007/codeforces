n,m=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
a=[i%2 for i in a]
b=[i%2 for i in b]
cc=[0,0]
dd=[0,0]
for i in a:
    cc[i]+=1
for i in b:
    dd[i]+=1
print(min(cc[0],dd[1])+min(cc[1],dd[0]))