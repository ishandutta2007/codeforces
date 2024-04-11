def s(x):
  return x % 10 + (x and s(x / 10))
k = int(raw_input())
ans = 0
while k > 0:
  if s(ans) == 10:
    k -= 1
  ans += 1
print ans-1