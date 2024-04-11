n = int(input())
ans = 0
for i in range(n):
    a,b,c = map(int, input().split(' '))
    if a+b+c >= 2 :
        ans += 1
print(ans)