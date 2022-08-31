from sys import stdout

def is_prime(n):
    for i in range(2, int(n**0.5)+1):
        if n%i == 0: return False
    return True

B = int(682)
a = []
for i in range(2, B+1):
    if is_prime(i):
        a.append(i)
#print(len(a))
#print(*a)

q = []
t = 1
for x in a:
    t *= x
    if t > 10**18:
        t //= x
        q.append(t)
        t = x
q.append(t)
L = len(q)
#print(len(q))
#print(*q)

test = int(input())
for _ in range(test):
    r = []
    prod = 0
    for x in q:
        print("? %d" % x)
        stdout.flush()
        y = int(input())
        r.append(y)
        prod *= y
    res = 1
    d = []
    for x in r:
        for p in a:
            if x%p == 0:
                d.append(p)
    dd = [1]*((len(d)+1)//2)
    for i in range(len(d)):
        t = 1
        p = d[i]
        while t*p <= 10**9: t *= p
        dd[i//2] *= t
    num = 1
    for t in dd:
        print("? %d" % t)
        stdout.flush()
        y = int(input())
        num *= y
        for p in a:
            if y%p == 0:
                cnt = 1
                while y%p == 0:
                    y /= p
                    cnt += 1
                res *= cnt
    res *= 2
    res = max(res, 8)
    print("! %d" % res)
    stdout.flush()