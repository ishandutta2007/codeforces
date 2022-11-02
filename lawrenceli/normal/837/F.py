n, k = map(long, raw_input().split())
A = list(map(long, raw_input().split()))
for i in range(len(A)):
    if A[i] > 0:
        A = A[i:]
        A.reverse()
        break

for i in A:
    if i >= k:
        print 0
        quit()

def check(m):
    tot = A[0]
    cur = 1
    for i in range(1, len(A)):
        cur = cur * (i + m - 1) // i
        if cur >= k: return True
        tot += cur * A[i]
        if tot >= k: return True
    return False

lo, hi = 1, k + 1
while lo < hi:
    mid = (lo + hi) / 2
    if check(mid): hi = mid
    else: lo = mid + 1

print lo