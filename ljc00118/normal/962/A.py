n = input()
n = int(n)
tmp, ans, ans1 = 0, 0, 0
a = input().split()
for i in range(0, n) :
    tmp += int(a[i])
while ans * 2 < tmp :
    ans += int(a[ans1])
    ans1 += 1
print(ans1)