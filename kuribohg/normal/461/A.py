n = int(input())
x = list(map(int,input().split()))
x.sort()
if n == 1:
    y = x[0]
else:
    y = 0
    for i in range(0, n - 1):
        y += (i + 2) * x[i]
    y += n * x[n - 1]
print(int(y))