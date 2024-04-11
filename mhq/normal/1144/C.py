n = int(input())
a = list(map(int, input().split()))
ans1 = []
ans2 = []
f = dict()
a.sort()
for x in a:
    if x in f:
        f[x] += 1
    else:
        f[x] = 1
for key, value in f.items():
    if value > 2:
        print("NO")
        exit(0)
    ans1.append(key)
    if value == 2:
        ans2.append(key)
print("YES")
ans2.reverse()
print(len(ans1))
print(" ".join(str(x) for x in ans1))
print(len(ans2))
print(" ".join(str(x) for x in ans2))