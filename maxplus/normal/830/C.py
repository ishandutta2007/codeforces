import itertools
import time

unfold = itertools.chain.from_iterable

t = time.time() + 1900
def jumps(a):
    d = speedup
    if time.time() > t:
        print(anss)
        exit(0)
    try:
        while True:
            c = (a + d - 1) // d
            d = (a + c - 2) // (c - 1)
            yield d
    except:
        return

#    while d < a - 1:
#        c = (a + d - 1) // d
#        d = (a + c - 2) // (c - 1)
#        yield d

def calc(d):
    return (d - 1) * len(a) - sum(i % d for i in a)

def ans1(D):
    for d in D:
        d -= 1
        if calc(d) <= k:
            return d
    return 1

def ans():
    for d, pd in zip(D, D[1:]):
        if time.time() > t:
            return anss
        d -= 1
        cd = calc(d)
        if cd <= k:
            return d
        if d == pd:
            continue
        cpd = calc(pd)
        if (d - pd) * (cd - cpd) >= ((cd - k) * (d - pd) + cd - cpd - 1):
            return d - ((cd - k) * (d - pd) + cd - cpd - 1) // (cd - cpd)
    return anss

n, k = map(int, input().split())
a = list(map(int, input().split()))
speedup = int(2 * max(a) ** 0.55)

lb = int(max(a) ** 0.1 + 10)

a = [i - 1 for i in a]
anss = ans1(sorted(range(2, lb + 1), reverse=True))
if anss <= lb / 2:
    print(anss)
    exit(0)

a = [i + 1 for i in a]
D = sorted(set(range(lb + 1, speedup + 1)).union(set([speedup, max(a) + k + 1]).union(set(
    unfold(map(jumps, a))))), reverse=True)

a = [i - 1 for i in a]
print(int(ans()))