import string
tst = int(input())
for it in range(tst):
  n, m = map(int, input().split())
  strings = []
  for i in range(n):
    new_string = input()
    strings.append(new_string)
  #strings of n strings of length m
  best_answer = 10 ** 9
  for i in range(n):
    for j in range(i + 1, n):
      #strings[i], strings[j]
      A = strings[i]
      B = strings[j]
      ans = 0
      for k in range(m):
        ans += abs(string.ascii_lowercase.index(A[k]) - string.ascii_lowercase.index(B[k]))
      if best_answer > ans:
        best_answer = ans
  print(best_answer)