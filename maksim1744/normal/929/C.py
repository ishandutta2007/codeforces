g, d, f = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = list(map(int, input().split()))
a = [[x, 0] for x in a]
b = [[x, 1] for x in b]
c = [[x, 2] for x in c]
m = a + b + c
m.sort()
m.append([10 ** 10, 3])
n = len(m)
i1 = 0
i2 = 0
s = [0, 0, 0, 0]
ans = 0
while i1 < n - 1:
    while m[i1][0] * 2 >= m[i2][0]:
        s[m[i2][1]] += 1
        i2 += 1
    u = m[i1][1]
    if u == 0:
        ans += s[1] * (s[1] - 1) * s[2] * (s[2] - 1) * (s[2] - 2) // 12
    elif u == 1:
        ans += s[0] * (s[1] - 1) * s[2] * (s[2] - 1) * (s[2] - 2) // 6
    else:
        ans += s[0] * s[1] * (s[1] - 1) * (s[2] - 1) * (s[2] - 2) // 4
    s[m[i1][1]] -= 1
    i1 += 1
print(ans)