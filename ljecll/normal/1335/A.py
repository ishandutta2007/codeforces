tc = int(input())

for i in range(tc):
    n = int(input())
    if (n % 2):
        print((n - 1) // 2)
    else:
        print((n - 2) // 2)