[n, k] = raw_input().split(' ')
n = int(n)
val = dict()
for i in range(n):
    a, w = raw_input().split(' ')
    if not val.has_key(a):
        val[a] = []
    val[a].append(int(w))

ans = 0
ans0 = 0

for s in val.keys():
    r = list(s)
    r.reverse()
    r = ''.join(r)
    if s == r:
        a = sorted(val[s], reverse=True)
        i = 0
        while i + 2 <= len(a) and a[i] + a[i + 1] > 0:
            ans += a[i] + a[i + 1]
            ans0 = max(ans0, -a[i + 1])
            i += 2
        if i < len(a) and a[i] > 0:
            ans0 = max(ans0, a[i])
    elif s < r and val.has_key(r):
        a = sorted(val[s], reverse=True)
        b = sorted(val[r], reverse=True)
        w = map(sum, zip(a, b))
        w = filter(lambda x: x > 0, w)
        ans += sum(w)

print ans + ans0