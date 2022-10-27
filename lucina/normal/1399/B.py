#python review 
#code and debug at atcoder.jp custom test
t = int(input())

for test_case in range(t) :
  n = int(input())
  a = [int(e) for e in input().split()]
  b = [int(e) for e in input().split()]
  
  min_a = 100000 * 100000
  min_b = 100000 * 100000
  
  for i in a:
    min_a = min(min_a, i)
  for i in b:
    min_b = min(min_b, i)
  ans = 0
  
  for i in range(n):
    dif = a[i] - min_a
    ans += dif
    b[i] -= dif
    if (b[i] < min_b):
      b[i] = min_b
  for i in range(n):
    ans += b[i] - min_b
  print(ans)