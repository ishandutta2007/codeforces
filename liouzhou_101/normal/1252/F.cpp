n = int(input())
a, b, c, d = n%2, n//2%2, n//4%2, n//8
d ^= 1
if d == 1: c ^= 1
if d == 1 and c == 1: b ^= 1
if d == 1 and c == 1 and b == 1: a ^= 1
print(a+b*2+c*4+d*8)