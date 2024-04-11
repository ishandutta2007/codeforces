n, m, dx, dy = map(int, input().split())

zero = [0] * n
x, y = 0, 0
for i in range(n):
    zero[x] = y
    x = (x + dx) % n
    y = (y + dy) % n

cnt = [0] * n
for _ in range(m):
    x, y = map(int, input().split())
    cnt[(y - zero[x]) % n] += 1

max_val = max(cnt)
max_pos = cnt.index(max_val)
print(0, max_pos)