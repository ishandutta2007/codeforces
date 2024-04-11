for _ in range(int(input())):
    n = int(input())
    a = [int(x) for x in input().split()]
    x = 2**30-1
    for i in range(n):
        if i != a[i]:
            x &= a[i]
    print(x)