n, k = map(int, input().split())
p = []
for i in range(n):
    p.append(list(input()))
cn = [[], [], []]
ok = k
for j, s in enumerate(p):
    for i, c in enumerate(s):
        if c != '.':
            continue
        t = int(i > 0 and s[i - 1] == 'S') + int(i < len(s) - 1 and s[i + 1] == 'S')
        cn[t].append([j, i])
cn = cn[0] + cn[1] + cn[2]
ans = 0
for ps in cn[:k]:
    p[ps[0]][ps[1]] = 'x'
z = ['P', 'S', 'x']
for j, s in enumerate(p):
    for i, c in enumerate(s):
        if c != 'S':
            continue
        t = int(i > 0 and s[i - 1]  in z) + int(i < len(s) - 1 and s[i + 1] in z)
        ans += t
print(ans)
print('\n'.join([''.join(s) for s in p]))