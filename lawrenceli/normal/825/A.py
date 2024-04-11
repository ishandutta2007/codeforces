n = map(int, raw_input())
s = raw_input() + '0'
ans, cur = 0, 0
for c in s:
    if c == '0': ans, cur = ans * 10 + cur, 0
    else: cur += 1
print ans