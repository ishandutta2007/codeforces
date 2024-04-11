n = int(input())
k = 1
while k * (k + 1) // 2 <= n:
    k += 1
k -= 1
print(k)
for i in range(1, k):
    print(i, end=' ')
print(n - k * (k - 1) // 2)