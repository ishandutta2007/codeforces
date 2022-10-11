for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))

    aa = 0
    bb = a[0]
    for i in range(1, n):
        if a[i] <= a[i - 1]:
            bb -= a[i - 1] - a[i]
        else:
            aa += a[i] - a[i - 1]

    ok = True
    ok &= bb >= 0
    ok &= aa <= a[-1]
    print("YES" if ok else "NO")