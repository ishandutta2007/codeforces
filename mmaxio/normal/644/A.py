n, a, b = map(int, input().split())

if n > a * b:
    print(-1)
else:
    for i in range(a):
        for j in range(b):
            val = i * b + 1
            val += (j if i % 2 == 0 else b - 1 - j)
            print(val if val <= n else 0, end = ' ')
        print()