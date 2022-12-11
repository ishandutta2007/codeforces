tc = int(input())

for i in range(tc):
    n, m = map(int, input().split())
    c = n % m
    if (c == 0):
        print(c)
    else:
        print(m - c)