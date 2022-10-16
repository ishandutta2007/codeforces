n,k = map(int, raw_input().split())
a = map(int, raw_input().split())
b = map(int, raw_input().split())
base = sum(b)
for i in range(n):
  a[i] -= b[i]
a = sorted(a)
for i in range(k):
  base += a[i]
for i in range(k,n):
  base += min(a[i], 0)
print base