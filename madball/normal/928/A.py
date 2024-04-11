def normalize(s):
    res = []
    for c in s.lower():
        if c == 'i' or c == 'l':
            res.append('1')
        elif c == 'o':
            res.append('0')
        else:
            res.append(c)
    return ''.join(res)


s = normalize(input().strip())
n = int(input())
for i in range(n):
    s2 = normalize(input().strip())
    if s == s2:
        print('No')
        break
else:
    print('Yes')