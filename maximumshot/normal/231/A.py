n = int(input())
res = 0
for _ in range(n):
    x = input().split(' ')
    c = sum([1 for t in x if t == '1'])
    if c >= 2:
        res += 1

print(res)