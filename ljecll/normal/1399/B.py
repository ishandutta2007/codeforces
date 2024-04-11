TC = int(input())

for tc in range(TC):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    mina = min(a)
    minb = min(b)
    ans = 0
    for i in range(n):
        ans += max(a[i] - mina, b[i] - minb)
    print(ans)