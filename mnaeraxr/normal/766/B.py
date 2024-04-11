n = int(input())

A = list(map(int, input().split()))

for i in range(n):
    for j in range(i):
        for k in range(j):
            a, b, c = A[i], A[j], A[k]
            if 2 * max(a, b, c) < a + b + c:
                print("YES")
                exit(0)
                
print("NO")