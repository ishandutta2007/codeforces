n = int(raw_input())
ans = 0
arr = map(int, raw_input().split())
socks = set()
for i in range(2 * n):
    if arr[i] in socks:
        socks.remove(arr[i])
    else:
        socks.add(arr[i])
    ans = max(ans, len(socks))
print ans