from sys import *
input = stdin.readline

n = int(input())
a = list(map(int, input().split()))

def solve(a, n):
    if n == 1:
        return []
    if n == 3:
        return [[1, 2, 3]]
    if n % 2 == 1:
        ops = []
        for i in range(0, n - 2, 2):
            ops.append([i + 1, i + 2, i + 3])
        for i in reversed(range(0, n - 3, 2)):
            ops.append([i + 1, i + 2, i + 3])
        return ops
    else:
        x = 0
        for y in a:
            x ^= y
        if x != 0:
            print('NO')
            exit(0)
        ops = [[1, 2, 3]]
        a = a[3:]
        add = solve(a, n - 3)
        for i in range(len(add)):
            ops.append([add[i][j] + 3 for j in range(3)])
        return ops


ops = solve(a, n)
print('YES')
print(len(ops))
for i in range(len(ops)):
    print(ops[i][0], ops[i][1], ops[i][2])