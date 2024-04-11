n, k = [int(x) for x in raw_input().split()]
a = [int(x) for x in raw_input().split()]
a.sort()
ans = 0
i = 0
while i < n:
    j = i
    while j < n and a[i] == a[j]:
        j += 1
    if j == n or a[j] > a[i]+k:
        ans += j-i
    i = j
print(ans)