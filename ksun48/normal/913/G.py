MOD = 10**18

def pow2(n):
    if n == 0:
        return 1
    if n % 2:
        return (2 * pow2(n-1)) % MOD
    c = pow2(n//2)
    return (c*c) % MOD

n = int(input())

start2 = pow2(1000)

p2 = [pow2(4*(5**x)) for x in range(50)]
c2 = [10**x for x in range(50)]
c3 = [4*(5**x) for x in range(50)]

for tt in range(n):
    q = int(input())
    f = q * 10**7
    f = f // (2**18)
    f = f + 1
    while(f % 5 == 0):
        f = f + 1
    f = f * (2**18)
    ans = 1000
    s2 = start2
    for i in range(1, 19):
        while((pow2(ans) % c2[i]) != (f % c2[i]) ):
            if(i == 1):
                ans = ans + 1
                s2 = (s2 * 2) % MOD
            elif(i > 1):
                ans = ans + c3[i-2]
                s2 = (s2 * p2[i-2]) % MOD
    print(ans)