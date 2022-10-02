W, M, K = map(int, input().split())


def f(N):
    ANS = 0
    for keta in range(1, 20):
        lo = 10**(keta - 1)
        hi = min(N, 10**keta - 1)
        cnt = max(hi - lo + 1, 0)
        ANS += keta * cnt
    return ANS


ok = 0
ng = 1 << 100
while ok + 1 < ng:
    x = (ok + ng) // 2
    if (f(M + x - 1) - f(M - 1)) * K <= W:
        ok = x
    else:
        ng = x
print(ok)