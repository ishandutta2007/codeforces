n, m = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]

def lower_bound(x) :
    bl = 0
    br = m - 1
    while br - bl > 1 :
        bm = (bl + br) // 2
        if b[bm] >= x : br = bm
        else : bl = bm + 1
    if b[bl] >= x : return bl
    elif b[br] >= x : return br
    else : return m

res = 0

for i in range(n) :
    pos = lower_bound(a[i])
    tmp = 2 * (10 ** 9) + 1
    if pos < m and tmp > b[pos] - a[i] :
        tmp = b[pos] - a[i]
    pos = lower_bound(a[i] + 1) - 1
    if pos >= 0 and tmp > a[i] - b[pos] :
        tmp = a[i] - b[pos]
    if tmp > res : res = tmp
print(res)