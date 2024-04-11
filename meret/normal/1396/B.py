t = int(input())
for _ in range(t):
  n = int(input())
  a = list(map(int, input().split()))
  if sum(a) < 2 * max(a):
    print("T")
  else:
    print("T" if sum(a) % 2 == 1 else "HL")