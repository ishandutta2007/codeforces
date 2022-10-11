for _ in range(int(input())):
    n, m = map(int, input().split())
    a = [list(map(int, input().split())) for _ in range(n)]

    els = []
    for i in range(n):
        for j in range(m):
            els.append([a[i][j], i, j])

    els.sort()
    j = 0
    i = 0
    while i < n * m:
        k = i
        while k < n * m and els[k][0] == els[i][0]:
            k += 1
        while i < k:
            a[els[i][1]][els[i][2]] += (els[i][1] + els[i][2] + j) % 2
            i += 1
        j += 1

    for i in range(n):
        print(*a[i])