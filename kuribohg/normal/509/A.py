n = int(input())
a = []
b = []
c = []
for x in range(n):
    a.append(b)
    for y in range(n):
        b.append(int(0))
for i in range(n):
    for j in range(n):
        if i == 0 or j == 0:
            a[i][j] = 1
            
        else:
            a[i][j] = a[i - 1][j] + a[i][j - 1]
        c.append(a[i][j])
print(max(c))