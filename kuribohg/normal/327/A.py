n = int(input())
x = list(map(int,input().split()))
y = []
if 0 not in x:
    print(int(n - 1))
else:
    for i in range(n):
        for j in range(i, n):
                t = x[i:(j + 1)].count(0) - x[i:(j + 1)].count(1)
                s = x.count(1) + t
                y.append(s)
    print(int(max(y)))