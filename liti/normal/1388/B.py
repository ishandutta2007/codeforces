t = int(input())

for i in range(t):
    n = int(input())
    k = (n+3)//4
    print('9'*(n-k) + '8'*k)