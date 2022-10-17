n, a, b = [int(x) for x in raw_input().split()]
e0, e1 = 0, 1
if a < b:
    a, b = b, a
    e0, e1 = e1, e0
if b != 1:
    print("NO")
elif a == 1 and 2 <= n <= 3:
    print("NO")
else:
    print("YES")
    s = [[e0] * n for _ in range(n)]
    for i in range(n-a):
        s[i][i+1] = s[i+1][i] = e1
    for i in range(n):
        s[i][i] = 0
        print ''.join([str(x) for x in s[i]])