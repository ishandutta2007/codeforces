from functools import lru_cache
import random


@lru_cache(None)
def f(N):
    if N == 0:
        return 0
    s = 0
    for d in range(10):
        if d > N:
            break
        s += d * ((N - d) // 10 + 1)
        s += f((N - d) // 10)
    return s


def main(a):
    d = a
    #  d 
    while True:
        d += a
        L = random.randint(10, 10**15)
        # (L, R]  d 
        ng = 0
        ok = 10 ** 18
        while ng + 1 < ok:
            mid = (ng + ok) // 2
            if(f(mid) - f(L) >= d):
                ok = mid
            else:
                ng = mid
        R = ok
        if(f(R) - f(L) == d):
            return L + 1, R


a = int(input())
print(*main(a))