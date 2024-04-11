test = int(input())
for i in range(test):
    n, k = map(int, input().split(' '))
    print(n - k + k // 2)
    s=''
    for j in range((k + 1) // 2, k):
        s += str(j)
        s += ' '
    for j in range(k + 1, n + 1):
        s += str(j)
        s += ' '
    print(s)