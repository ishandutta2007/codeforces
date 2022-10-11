t = int(input())
for te in range(t):
    n, B, x, y = [int(x) for x in input().split()]
    ans, cur = 0, 0
    for i in range(n):
        if cur + x <= B:
            cur += x
        else:
            cur -= y
        ans += cur
    print(ans)