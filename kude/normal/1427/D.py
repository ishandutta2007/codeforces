n = int(input())
def sf(a, d):
    s = [0]
    for di in d:
        s.append(s[-1] + di)
    rv = []
    for i in range(len(d) - 1, -1, -1):
        rv += a[s[i]:s[i+1]]
    return rv
c = list(map(int, input().split()))
ans = []
while True:
    for i in range(n):
        if c[i] != i+1:
            break
    else:
        break
    for k in range(i, n):
        if c[k] + 1 != c[k+1]:
            break
    s = c[i]
    for j in range(k+1, n):
        if c[j] == s-1:
            break
    t = [i, k - i + 1, j - k, n - (i + k - i + 1 + j - k)]
    t = list(filter(lambda x: x != 0, t))
    ans.append(t)
    c = sf(c, ans[-1])
    #print(ans[-1])
    #print(c)
print(len(ans))
for a in ans:
    print(len(a), *a)