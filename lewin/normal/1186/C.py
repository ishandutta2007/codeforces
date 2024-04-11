a = raw_input()
b = raw_input()
sb = sum(map(int, b))

cs = [0]
for i in xrange(len(a)):
    cs.append(cs[-1] + ord(a[i]) - ord('0'))

ans = 0
for i in xrange(len(b), len(a)+1):
    if (cs[i]+cs[i-len(b)]+sb)%2 == 0:
        ans += 1
print ans