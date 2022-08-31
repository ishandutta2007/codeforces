n, a, b = list(map(int, input().split()))
s = input()
s += '*'
n += 1
m = []
i = 0
i1 = -1
while i < len(s):
    if s[i] == '*':
        if i - i1 > 1:
            m.append(i - i1 - 1)
        i1 = i
    i += 1
sm = a + b
for c in m:
    if c % 2 == 0:
        a = max(0, a - c // 2)
        b = max(0, b - c // 2)
    else:
        if a > b:
            a = max(0, a - (c + 1) // 2)
            b = max(0, b - c // 2)
        else:
            b = max(0, b - (c + 1) // 2)
            a = max(0, a - c // 2)
print(sm - a - b)