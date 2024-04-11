n = int(input())
a = list(map(int, input().split()))
if n == 1:
  print(1, 1)
  print(0)
  print(1, 1)
  print(0)
  print(1, 1)
  print(-a[0])
else:
  print(1, n)
  for i in range(n):
    added = (n - 1 - (a[i] % (n - 1))) * n
    a[i] += added
    print(added, end=' ')
  print()
  print(1, n - 1)
  for i in range(n - 1):
    print(-a[i], end=' ')
  print()
  print(n, n)
  print(-a[n - 1])