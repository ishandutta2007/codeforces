n = int(input())
A = B = C = 0
for i in range(n):
    a,b,c = map(int, input().split(' '))
    A += a
    B += b
    C += c
if A == 0 and B == 0 and C == 0 :
    print('YES')
else :
    print('NO')