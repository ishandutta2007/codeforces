s = raw_input()
r = s.index("R") % 4
b = s.index("B") % 4
g = s.index("G") % 4
y = s.index("Y") % 4
perm = [r, b, y, g]
iperm = [0, 0, 0, 0]
for i in range(4):
    iperm[perm[i]] = i

res = [0, 0, 0, 0]
for i in range(len(s)):
    if s[i] == '!':
        res[iperm[i%4]] += 1
print " ".join(map(str, res))