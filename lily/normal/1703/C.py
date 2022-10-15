T = int(input())
while T > 0:
    T -= 1
    n = int(input())
    a = list(map(int, input().split()))
    for i in a:
        x, y = input().split()
        for j in y:
            if j == 'D':
                i += 1
            else:
                i -= 1
        i %= 10
        i += 10
        i %= 10
        print(i, end=' ')
    print()