n, k = map(int, input().split())
tmp = list(map(int, input().split()))
ans = 0
for x in tmp:
    if (x >= tmp[k - 1]) and (x > 0):
        ans = ans + 1
print(ans)