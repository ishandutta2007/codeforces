n, m = list(map(int, input().split()))
p = list(map(int, input().split()))
for _ in range(m):
    l, r, x = map(int, input().split())
    l -= 1
    r -= 1
    x -= 1
    t = p[x]
    a = sum(map(lambda s : s < t, p[l:r+1]))
    if a == x - l: print("Yes")
    else: print("No")