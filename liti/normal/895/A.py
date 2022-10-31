n = int(input())
a = list(map(int,input().split()))
a = a + a
ans = 360
for i in range(n):
    for j in range(n):
        v = sum(a[i:i+j+1])
        ans = min(ans, abs(360 - v - v))
print(ans)