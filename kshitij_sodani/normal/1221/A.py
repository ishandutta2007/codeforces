q=int(input())
p=1

dp=[0 for i in range(40)]
for _ in range(q):
    n=int(input())
    it=list(map(int,input().split()))
    it=[i for i in it if i<=2048]
    if sum(it)>=2048:
        print("YES")
    else:
        print("NO")