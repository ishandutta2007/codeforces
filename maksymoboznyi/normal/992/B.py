def gcd(a, b):
    while a != 0 and b != 0:
        if a <= b:
            b = b % a
        else:
            a = a % b
    return max(a, b)

l, r, x, y = map(int, input().split())

if y % x != 0:
    print(0)
    exit()

ans = 0
i = 1
while i * i <= (y // x):
    if (y // x) % i == 0:
        #1st option
        c = i
        d = (y // x) // c
        
        a = c * x
        b = d * x
        
        if l <= a and a <= r and l <= b and b <= r and gcd(a, b) == x:
            ans += 1
        
        #2nd option
        if i * i != (y // x):
            c = (y // x) // i
            d = (y // x) // c
            
            a = c * x #c = 2, a = 2x
            b = d * x #d = 4, b = 4x
            
            if l <= a and a <= r and l <= b and b <= r and gcd(a, b) == x:
                ans += 1
                
    i += 1
print(ans)