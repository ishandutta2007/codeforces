n = int(input())
l = list(map(int,input().split()))
a = []
for i in range(n):
    a.append(int(l[i] % 2))
if a.count(0) > a.count(1):
    print(int(a.index(1) + 1))
else:
    print(int(a.index(0) + 1))