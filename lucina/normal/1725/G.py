a = int(input())
if a <= 2:
    print(2*a+1)
else:
    x = (a//3+1)*4+a%3-1
    print(x)