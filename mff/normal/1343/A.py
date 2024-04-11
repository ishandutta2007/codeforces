t = int(input())

for i in range(t):
    a = int(input())
    k = 2
    
    while a % (2**k - 1) > 0:
        k += 1
    
    print(a // (2**k - 1))