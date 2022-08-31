n = int(input())
a = list(map(int, input().split()))
f = dict()
for x in a:
    if x in f:
        f[x] += 1
    else:
        f[x] = 1
max_val = 0
who = 0
for key, value in f.items():
    if value > max_val:
        max_val = value
        who = key
ind = -1
ans = []
for j in range(0, len(a)):
    if a[j] == who:
        ind = j
        break
assert(ind != -1)
for j in range(ind + 1, len(a)):
    if a[j] == who:
        continue
    if a[j] > who:
        ans.append((2, j, j - 1))
    else:
        ans.append((1, j, j - 1))
for j in range(ind - 1, -1, -1):
    if a[j] == who:
        continue
    if a[j] > who:
        ans.append((2, j, j + 1))
    else:
        ans.append((1, j, j + 1))
print(len(ans))
for t, i, j in ans:
    print(t, i + 1, j + 1)