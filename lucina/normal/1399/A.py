#python review 
#code and debug at atcoder.jp custom test
t = int(input())

for test_case in range(t) :
  n = int(input())
  a = [int(e) for e in input().split()]
  a.sort()
  ok = True
  for i in range(n - 1):
    if (a[i + 1] - a[i] >= 2):
      ok = False;
  print("YES" if ok else "NO")