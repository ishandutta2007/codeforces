def check(np, nq):
  return np >= x and nq >= y and (np - x <= nq - y)

t = int(input())
for i in range (t):
  x, y, p, q = map(int, input().split())
  l = 0
  r = 10 ** 18 #pashm
  while l < r - 1:
    m = (l + r) // 2
    if check(p * m, q * m):
      r = m
    else:
      l = m
  if r == 10 ** 18:
    print (-1)
  else:
    ans = q * r - y
    print(ans)