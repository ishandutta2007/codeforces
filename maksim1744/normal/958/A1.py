def check(x, y):
    return ''.join([''.join(s) for s in x]) == ''.join([''.join(s) for s in y])

n = int(input())
a = [list(input()) for i in range(n)]
b = [list(input()) for i in range(n)]
for i in range(4):
    for j in range(2):
        if check(a, b):
            print('Yes')
            exit(0)
        b = b[::-1]
    for j in range(2):
        if check(a, b):
            print('Yes')
            exit(0)
        b = [s[::-1] for s in b]
    c = [['' for t in range(n)] for u in range(n)]
    for t in range(n):
        for u in range(n):
            c[t][u] = b[u][n - t - 1]
    b = c[:]
    if check(a, b):
        print('Yes')
        exit(0)
print('No')