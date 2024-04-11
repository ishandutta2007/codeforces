from math import factorial


def binomial(n, k):
  if n < k:
    return 0
  return factorial(n)/(factorial(k) * factorial(n - k))

n, p = list(input().split())

n = int(n)
p = float(p)

l, r = 0, n

while l < r:
  k = (l + r)//2
  cur = binomial(k, 3)/binomial(n, 3) + binomial(k, 2) * (n - k)/binomial(n, 3) + k * binomial(n - k, 2)/binomial(n, 3)/2
  if cur < p:
    l = k + 1
  else:
    r = k

print(l)