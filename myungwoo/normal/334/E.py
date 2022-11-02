N,M = map(int,raw_input().split())

P = {}
Q = {}
for i in range(10001):
    for j in range(1,5):
        P[(i,j)] = set()
        Q[(i,j)] = set()

for i in range(10):
    P[(i,1)].add(i)
    Q[(i,1)].add(i)
for i in range(100):
    P[(i,2)].add(i)
    Q[(i,2)].add(i)
    a,b = i/10,i%10
    next = [a+b,abs(a-b),a*b]
    for j in next:
        P[(j,2)].add(i)
        Q[(i,2)].add(j)
for i in range(1000):
    P[(i,3)].add(i)
    Q[(i,3)].add(i)
    candidate = [((i/100,1),(i%100,2)),((i/10,2),(i%10,1))]
    next = []
    for p,q in candidate:
        for a in Q[p]:
            for b in Q[q]:
                next.append(a+b)
                next.append(abs(a-b))
                next.append(a*b)
    next = set(next)
    for j in next:
        P[(j,3)].add(i)
        Q[(i,3)].add(j)
for i in range(10000):
    P[(i,4)].add(i)
    Q[(i,4)].add(i)
    candidate = [((i/1000,1),(i%1000,3)),((i/100,2),(i%100,2)),((i/10,3),(i%10,1))]
    next = []
    for p,q in candidate:
        for a in Q[p]:
            for b in Q[q]:
                next.append(a+b)
                next.append(abs(a-b))
                next.append(a*b)
    next = set(next)
    for j in next:
        P[(j,4)].add(i)
        Q[(i,4)].add(j)

def f(n,m,p):
    for i in range(10000):
        for j in p[(abs(n-i),4)]:
            print '%04d%04d'%(i,j)
            m -= 1
            if m == 0:
                return

f(N,M,P)