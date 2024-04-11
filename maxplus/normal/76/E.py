import sys
n = int(input())
ssq = 0
sqs0 = 0
sqs1 = 0
for _ in range(n):
  a, b = sys.stdin.readline().split()
  a, b = int(a), int(b)
  ssq += a*a+b*b
  sqs0 += a
  sqs1 += b
print(n * ssq - sqs0**2 - sqs1**2)