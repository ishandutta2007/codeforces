for _ in range(int(input())):
    n = int(input())
    x = 10 ** 9
    y = 0
    # from left num in [0, x] can be taken away and updated x to the num
    # the same for right but in [y, inf)
    # greadily keep x as large as possible and y vice versa
    for a in map(int, input().split()):
        if a < x + y:
            x = a - y
            if x < 0:
                print('NO')
                break
        else:
            y = a - x
    else:
        print('YES')