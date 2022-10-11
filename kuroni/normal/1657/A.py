import math

t = int(input())
for i in range(t):
    x, y = [int(x) for x in input().split()]
    if x == 0 and y == 0:
        print(0)
    elif int(math.sqrt(x ** 2 + y ** 2)) ** 2 == x ** 2 + y ** 2:
        print(1)
    else:
        print(2)