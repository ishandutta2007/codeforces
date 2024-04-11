import sys

def stable_marriage(p1, p2):
    n = len(p1)
    ret = [-1 for __ in xrange(2*n)]

    free = [True for __ in xrange(n)]
    nfree = n
    def engage(m,w):
        ret[w+n] = m
        ret[m] = w+n
        free[m] = False

    while nfree > 0:
        m = next(i for i in xrange(n) if free[i])
        idx = 0
        while free[m]:
            w = p1[m][idx]
            if ret[w+n] == -1:
                engage(m,w)
                nfree -= 1
            else:
                m1 = ret[w+n]
                if p2[w].index(m) < p2[w].index(m1):
                    free[m1] = True
                    ret[m1] = -1
                    engage(m,w)
            idx += 1
    return ret

def process_one():
    n = int(raw_input())
    grid = [map(int, raw_input().split()) for __ in xrange(n)]

    print "B"
    sys.stdout.flush()

    x,d = raw_input().split()
    d = int(d)

    sign = -1 if ((x == 'I') ^ (d <= n)) else 1

    partner = stable_marriage(
        [sorted(range(n), key=lambda x: +sign*grid[i][x]) for i in xrange(n)],
        [sorted(range(n), key=lambda x: -sign*grid[x][i]) for i in xrange(n)],
    )

    while True:
        if d == -1: return
        if d == -2: sys.exit(0)
        print partner[d-1]+1
        sys.stdout.flush()
        d = int(raw_input())

t = int(raw_input())
for ___ in xrange(t):
    process_one()