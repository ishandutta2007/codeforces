def norm(s):
    d = ord('A') - ord('a')
    s11 = ''
    for i in range(len(s)):
        if ord('a') <= ord(s[i]) <= ord('z'):
            s11 += chr(ord(s[i]) + d)
        else:
            s11 += s[i]
    s = s11
    s = s.replace('O', '0')
    s = s.replace('L', '1')
    s = s.replace('I', '1')
    return s

s = norm(input())
n = int(input())
ok = True
for i in range(n):
    s1 = input()
    if norm(s1) == s:
        ok = False
        break
if ok:
    print('Yes')
else:
    print('No')