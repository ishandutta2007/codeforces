for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    for x, y in zip(a, a[1:]):
        if x <= y:
            print('Yes')
            break
    else:
        print('No')