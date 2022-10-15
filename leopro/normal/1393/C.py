t = int(input())
for test in range(t):
    n = int(input())
    a = [int(x) for x in input().split()]
    cnt = [0] * n
    for x in a:
        cnt[x - 1] += 1
    print((n - cnt.count(max(cnt))) // (max(cnt) - 1) - 1)