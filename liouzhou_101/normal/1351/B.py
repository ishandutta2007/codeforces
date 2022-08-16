for _ in range(int(input())):
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    flag = False
    for i, x in enumerate(a):
        for j, y in enumerate(b):
            if x == y:
                if a[1-i]+b[1-j] == x:
                    flag = True
    print("Yes" if flag else "No")