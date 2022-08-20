n, k = list(map(int, input().split()))
a = list(map(int, input().split()))
x = a[0]
i = 1
il = 0
c = 1
while i < n:
    if a[i] <= x + k:
        i += 1
    else:
        if il == i - 1:
            print(-1)
            break
        x = a[i - 1]
        il = i - 1
        c += 1
else:
    print(c)