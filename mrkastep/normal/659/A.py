a = []

for i in input().split():
    a.append(int(i))

ans = (a[1]+a[2]+a[0])%a[0]
if ans==0:
    ans = a[0]

print(str(ans))