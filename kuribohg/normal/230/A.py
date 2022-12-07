s, n = map(int,input().split())
A = []
B = []
for i in range(n):
    a, b = map(int, input().split())
    A.append(a)
    B.append(b)
j = len(A)
while j > 0:
    if s <= min(A):
        print("NO")
        break
    else:
        k = A.index(min(A))
        s += B[k]
        del A[k]
        del B[k]
        j -= 1    
    if j == 0:
        print("YES")