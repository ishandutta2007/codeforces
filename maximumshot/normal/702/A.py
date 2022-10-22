n = int(input())
a = [int(i) for i in input().split()]
res = 1
dp = 1
for i in range(1, n) :
    if a[i] > a[i - 1] : dp += 1
    else : dp = 1
    if dp > res : res = dp
print(res)