t = int(input())

for tc in range(t):
    n = int(input())
    num = [0, 0]
    arr = list(map(int, input().split()))
    for i in range(2 * n):
        c = arr[i]
        num[c % 2] += 1
    print("Yes" if num[0] == n and num[1] == n else "No")