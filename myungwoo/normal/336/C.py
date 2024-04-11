N = input()
A = map(int,raw_input().split())
B = []

for i in range(30):
    v = 2**i
    tmp = []
    for n in A:
        if n&v > 0:
            tmp.append(n)
    if not tmp:
        continue
    d = tmp[0]
    for n in tmp:
        d &= n
    if d&(v-1) == 0:
        B = tmp
print len(B)
for n in B: print n,