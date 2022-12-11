TC = int(input())

for tc in range(TC):
    n = int(input())
    a = list(map(int, input().split()))
    num = [[0, 0], [0, 0]]
    for i in range(n):
        num[i % 2][a[i] % 2] += 1
    if (num[0][1] != num[1][0]):
        print(-1)
    else:
        print(num[0][1])