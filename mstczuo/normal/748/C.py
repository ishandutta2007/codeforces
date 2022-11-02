n = input()
s = raw_input()
g = [set(), set()]
ans = 1

for c in s:
    i = 0 if c in 'UD' else 1
    g[i].add(c)
    if len(g[i]) > 1:
        ans += 1
        g = [set(), set()]
        g[i].add(c)

print ans