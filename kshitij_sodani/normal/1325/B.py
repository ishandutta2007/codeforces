#list(map(int,input().split()))
t=int(input())
for _ in range(t):
    n=int(input())
    it=list(map(int,input().split()))
    print(len(set(it)))