n = int(input())
x = []
k = 0
for i in range(n):
    a, b = map(int,input().split())
    k = k - a + b
    x.append(k)
print(max(x))