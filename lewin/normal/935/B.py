n = int(raw_input())
s = raw_input()
bal = 1 if s[0] == 'U' else -1
ps = bal
c = 0
for i in range(1,n):
  bal += 1 if s[i] == 'U' else -1
  if bal == 1 and ps < 0:
    c += 1
    ps = 1
  if bal == -1 and ps > 0:
    c += 1
    ps = -1
print c