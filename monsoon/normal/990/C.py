from collections import defaultdict

def brackets(s, isrev=False):
    opens = 0
    for c in (s[::-1] if isrev else s):
        if c == (')' if isrev else '('):
            opens += 1
        else:
            if not opens:
                return None
            opens -= 1
    return opens

m1 = defaultdict(int)
m2 = defaultdict(int)

n = int(raw_input())
for i in range(n):
    s = raw_input()
    b1 = brackets(s)
    b2 = brackets(s, True)
    m1[b1] += 1
    m2[b2] += 1

ans = 0
for key in m1.iterkeys():
    if key is not None:
        ans += m1[key] * m2[key]
print(ans)