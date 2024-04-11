n = int(raw_input())

t = []

s = 0

while True:
    l = 1
    r = 10**15
    while l < r:
        c = (l + r) // 2
        if (c+1)**3 - c**3 > s:
            r = c
        else:
            l = c + 1
    if s + l ** 3 > n:
        break
    t.append(l)
    s += l**3
    
ub = n
    
for i in range(len(t) - 1, 0, -1):
    while s + (t[i] + 1)**3 - t[i]**3 <= ub:
        s += (t[i] + 1)**3 - t[i]**3
        t[i] += 1
    ub = min(ub, sum(x**3 for x in t[i:]) + (t[i] + 1)**3 - t[i]**3 - 1)

print len(t), s