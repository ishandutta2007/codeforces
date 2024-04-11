TC = int(input())

for tc in range(TC):
    n = int(input())
    arr = list(map(int, input().split()))
    arr.sort()
    ans = (1 << 30)
    for i in range(n - 1):
        ans = min(ans, arr[i + 1] - arr[i])
    print(ans)