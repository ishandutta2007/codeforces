n = input()
k = len(n)
ans = 100
for i in range(2 ** k):
    s = bin(i)[2:]
    s = '0' * (k - len(s)) + s
    sq = ''
    for j in range(k):
        if s[j] == '1':
            sq += n[j]
    if sq == '' or sq[0] == '0':
        continue
    sq = int(sq)
    l = 0
    r = 1000000
    while r - l > 1:
        c = (r + l) // 2
        if c * c > sq:
            r = c
        else:
            l = c
    if l * l == sq:
        ans = min(ans, s.count('0'))
if ans == 100:
    print(-1)
else:
    print(ans)