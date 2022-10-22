for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    d = [0] * 35
    ans = 0
    for x in a:
        k = x.bit_length() - 1
        ans += d[k]
        d[k] += 1
    print(ans)