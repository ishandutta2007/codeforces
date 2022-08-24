tst = int(input())
for it in range(tst):
  n = int(input())
  a = list(map(int, input().split()))
  freq_array = [0 for i in range(n + 1)]
  for i in range(n):
    freq_array[a[i]] += 1
  answer = -1
  for j in range(1, n + 1):
    if freq_array[j] >= 3:
      answer = j
  print(answer)