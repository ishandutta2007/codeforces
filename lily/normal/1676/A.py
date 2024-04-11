n = int(input())
while n > 0:
    n -= 1
    t = int(input())
    a, b = 0, 0
    for i in range(6):
        a += t % 10
        t //= 10
        if i == 2:
            b = a
            a = 0
    print("YES" if a == b else "NO")