def gcd(a,b):
  return a if b == 0 else gcd(b, a % b)
n = int(raw_input())
bs = 0
for i in range(n+1):
  a = i
  b = n-i
  if a < b and gcd(a,b) == 1 and a > bs:
    bs = a

print bs,(n-bs)