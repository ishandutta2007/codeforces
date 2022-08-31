n = int(input())
a = list(map(int, input().split()))
vals = [[] for i in range(2)]
for x in a:
    vals[x % 2].append(x)
cnt = [len(vals[i]) for i in range(0, 2)]
for i in range(0, 2):
    vals[i].sort()
    vals[i].reverse()
best = 2 * 10 ** 9
for start in range(0, 2):
    if not vals[start]:
        continue
    can = min(len(vals[start]), len(vals[start ^ 1]))
    for i in range(0, 2):
        f = [can, can]
        f[start] += i
        if f[start] > len(vals[start]):
            continue
        cur_val = 0
        for k in range(0, 2):
            for j in range(0, len(vals[k])):
                if j >= f[k]:
                    cur_val += vals[k][j]
        best = min(best, cur_val)
print(best)