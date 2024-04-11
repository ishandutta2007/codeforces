def solve():
    n, m = map(int, input().split())
    xor_val = [0 for i in range(n + m)]
    for i in range(n):
        a = [ int(x) for x in input().split()]
        for j in range(m):
            xor_val[i+j] ^= a[j]
    for i in xor_val:
        if i != 0 :
            return 1
            
    return 0

T = int(input())
for ii in range(T):
    x = solve()
    if x == 0:
        print('Jeel')
    else:
        print('Ashish')