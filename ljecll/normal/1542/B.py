tc = int(input())

for i in range(tc):
    n, a, b = map(int, input().split())
    
    res = False
    pw = 1
    while(pw <= n):
        if ((n - pw) % b == 0):
            res = True
            break
        if (a == 1):
            break
        pw *= a
    
    print("Yes" if res else "No")
    # you have to be able to subtract some a^k and get a multiple of b