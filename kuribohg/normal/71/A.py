n = int(input())
for i in range(n):
    x = input()
    if len(x) <= 10:
        print(x)
    else :
        a = x[0]
        b = x[-1]
        y = str(a) + str(len(x) - 2) + str(b)
        print(y)