#python review 
#code and debug at atcoder.jp custom test
t = int(input())

for test_case in range(t) :
  n = int(input())
  l = [0] * (n + n + 1)
  a = [int(e) for e in input().split()]
  for i in a:
    	l[i] += 1
  ans = 0
  for s in range(2 * n + 1):
    sum = 0
    #damn you 0-index language
    for i in range(s // 2 + 1):
      if (i != s - i):
        sum += min(l[i], l[s - i])
      else :
        sum += (l[i] // 2)
    ans = max(ans, sum)
  print(ans)