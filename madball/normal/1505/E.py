n, m = map(int, input().split())
ar = [input() for i in range(n)]
x = 0
y = 0
res = 0
while True:
    res += 1 if ar[x][y] == '*' else 0
    if x == n - 1 and y == m - 1:
        break
    elif x == n - 1:
        y += 1
    elif y == m - 1:
        x += 1
    elif ar[x][y + 1] == '*':
        y += 1
    elif ar[x + 1][y] == '*':
        x += 1
    else:
        y += 1
print(res)