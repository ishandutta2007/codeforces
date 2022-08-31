n = int(input())

num = 0
for x in range(1, 110000):
  if n % x == 0:
    num = num + 1
print(num - 1)