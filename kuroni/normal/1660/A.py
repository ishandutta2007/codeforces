t = int(input())
for te in range(t):
    a, b = [int(x) for x in input().split()]
    if a == 0:
        print(1)
    else:
        print(a + b * 2 + 1)