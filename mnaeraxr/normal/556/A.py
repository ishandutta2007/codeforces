input()
s = input()
ans = 0
for i in s:
 if i == '1':
  ans += 1
 else:
  ans -= 1
print(abs(ans))