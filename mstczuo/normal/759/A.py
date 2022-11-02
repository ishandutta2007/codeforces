n = input()
a = map(int, raw_input().split(' '))
a = map(lambda x: x-1, a)
cc, ct, ans = 0, 0, 0
for i in range(n):
    if a[i] == i:
        ct += 1
    elif a[i] != -1:
        cc += 1
        x = i
        while x != -1:
            y, x, a[y] = x, a[x], -1
ans += 1 - raw_input().count('1') % 2
if cc + ct == 1:
    pass
else:
    ans += cc + ct
print ans