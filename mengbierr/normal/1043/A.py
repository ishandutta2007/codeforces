n=int(input())
a=list(map(int,input().split(" ")))
sum=0
minn=0
for i in range(len(a)):
    sum+=a[i]
    minn=max(minn,a[i])
while minn*n-sum<=sum:
    minn=minn+1
print(minn)