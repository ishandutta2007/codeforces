t = int(input())
for __ in range(t):
    n0,n2,n1 = map(int, input().split())
    if n2 == 0:
        if n0 > 0:
            ret = "0" * (n0+1)
        else:
            ret = "1" * (n1+1)
    else:
        ret = "0" * (n0+1) + "1" * (n1+1)
        n2 -= 1
        last = 0
        while n2 > 0:
            ret += str(last)
            last ^= 1
            n2 -= 1

    print(ret)