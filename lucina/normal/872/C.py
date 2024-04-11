a = int(input())
for i in range(a):
    k = int(input())
    if k in [1,2,3,5,7,11] : print(-1)
    elif k in [4,6,9] : print(1)
    elif k in [8,10,13,15] : print(2)
    elif k in [12,14] : print(3)
    elif k % 2 == 0 : print(k//4)
    else: print(k//4-1)