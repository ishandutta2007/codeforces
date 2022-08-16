#list(map(int,input().split()))
n=int(input())
aa=list(map(int,input().split()))
bb=[aa[0]]
ma=aa[0]
ind=0

for i in range(1,n):
    if aa[i]>ma:
        bb.append(ma+aa[i])
    else:
        bb.append(ma+aa[i])
    if bb[i]>ma:
        ma=bb[i]
        ind=i
        
print(*bb)