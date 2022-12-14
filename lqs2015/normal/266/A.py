n = int(input())
s = input()
ans = 0
for i in range (1, n):
    if s[i - 1] == s[i] :
        ans += 1
print(ans)