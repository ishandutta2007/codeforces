for _ in range(int(input())):
    n, x = map(int, input().split())
    if 1 <= n <= 2:
        print(1)
        continue
    now = 2
    for s in range(3, 9999, x):
        if s <= n < s + x:
            print(now)
            break
        now += 1