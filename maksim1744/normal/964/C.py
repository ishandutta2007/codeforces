mod = 10 ** 9 + 9

def gcd(a, b):
    if a == 0:
        return b, 0, 1
    d0, x0, y0 = gcd(b % a, a)
    x = y0 - (b // a) * x0
    y = x0
    return d0, x, y

def pow(a, k):
    if k == 0:
        return 1
    if k == 1:
        return a
    if k % 2 == 1:
        return (pow(a, k - 1) * a) % mod
    return (pow(a, k // 2) ** 2) % mod

n, a, b, k = map(int, input().split())
s = input()
pa = [1]
pb = [1]
for i in range(k):
    pa.append((pa[-1] * a) % mod)
    pb.append((pb[-1] * b) % mod)
ak = pa[k]
ans = pow(ak, (n + 1 - k) // k)
sk = 0
for i in range(k):
    if s[k - i - 1] == '+':
        sk += (pb[k - i - 1] * pa[i] * ans) % mod
    else:
        sk -= (pb[k - i - 1] * pa[i] * ans) % mod
while sk < 0:
    sk += mod
inva = list(gcd(ak, mod))[1]
inva = inva % mod
while inva < 0:
    inva += mod
ans = 0
bk = pb[k]
ak = inva
q = (ak * bk) % mod
c = (n + 1) // k
if q == 1:
    print((sk * c) % mod)
    exit(0)
if q == 0:
    print(sk)
    exit(0)
qn = pow(q, c)
invq = list(gcd(q - 1, mod))[1] % mod
while invq < 0:
    invq += mod
print((sk * (qn - 1) * invq) % mod)