T = int(input())
while T > 0:
    T -= 1
    n = int(input())
    a = []
    for i in range(n):
        a.append(input())
    ans = 0
    for i in range(n):
        for j in range(n):
            s = {(i, j), (j, n - i - 1), (n - 1 - i, n - 1 - j), (n - j - 1, i)}
            if (i, j) == min(s):
                c0, c1 = 0, 0
                for p in s:
                    if a[p[0]][p[1]] == '0':
                        c0 += 1
                    else:
                        c1 += 1
                ans += min(c0, c1)
    print(ans)