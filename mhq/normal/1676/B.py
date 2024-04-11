tst = int(input())
for it in range(tst):
  n = int(input())
  a = list(map(int, input().split()))
  min = a[0]
  for i in range(len(a)):
    if a[i] < min:
      min = a[i]
  print(sum(a)-(min*len(a)))