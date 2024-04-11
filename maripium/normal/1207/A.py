tt = int(input())
for tc in range(tt):
    b, p, f = map(int, input().split())
    h, c = map(int, input().split())
    b //= 2
    ans = 0
    for nb in range(min(b, p) + 1):
        ans = max(ans, nb * h + min(b - nb, f) * c)
    print(ans)