tc = int(input())

for i in range(tc):
    n = int(input())
    arr = list(map(int, input().split()))
    arr.sort()
    res = True
    for j in range(n - 1):
        if (arr[j + 1] - arr[j] > 1):
            res = False
    print("Yes" if res else "No")