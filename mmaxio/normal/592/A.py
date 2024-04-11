f = [input() for _ in range(8)]
ca, cb = 8, 8
for col in range(8):
  for row in range(8):
    if f[row][col] == 'W':
      ca = min(ca, row)
    if f[row][col] != '.':
      break
  for row in range(7, -1, -1):
    if f[row][col] == 'B':
      cb = min(cb, 7 - row)
    if f[row][col] != '.':
      break
print('A' if ca <= cb else 'B')