T = int(input())
while T > 0:
    T -= 1
    n = int(input())
    start = 2 if n % 3 != 1 else 1
    ans = ''
    while n > 0:
        n -= start
        ans += str(start)
        start = 3 - start
    print(ans)