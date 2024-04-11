n = int(raw_input())
x = map(int, raw_input().split())
y = map(int, raw_input().split())
s = set(x+y)
c = 0
for i in range(n):
  for j in range(n):
    if x[i]^x[j] in s:
      c ^= 1

print (c == 0) * "Karen" or "Koyomi"