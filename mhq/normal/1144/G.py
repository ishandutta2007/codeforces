n = int(input())
a = list(map(int, input().split()))
inf = 10 ** 6
inc = [inf for i in range(0, n + 1)]
dec = [-inf for i in range(0, n + 1)]
trinc = [-1 for i in range(0, n + 1)]
trdec = [-1 for i in range(0, n + 1)]
inc[0] = -inf
dec[0] = inf
#inc means last dec was in i and we want minimize last inc
for i in range(0, n - 1):
    if a[i + 1] < a[i]:
        if inc[i + 1] > inc[i]:
            inc[i + 1] = inc[i]
            trinc[i + 1] = 1
    if a[i + 1] > a[i]:
        if dec[i + 1] < dec[i]:
            dec[i + 1] = dec[i]
            trdec[i + 1] = 1
    if a[i + 1] > inc[i]:
        if dec[i + 1] < a[i]:
            dec[i + 1] = a[i]
            trdec[i + 1] = 0
    if a[i + 1] < dec[i]:
        if inc[i + 1] > a[i]:
            inc[i + 1] = a[i]
            trinc[i + 1] = 0
if inc[n - 1] == inf and dec[n - 1] == -inf:
    print("NO")
    exit(0)
now_inc = False
ans = [0 for i in range(0, n)]
if inc[n - 1] != inf:
    now_inc = True
for i in range(n - 1, -1, -1):
    if now_inc:
        ans[i] = 1
        if trinc[i] == 0:
            now_inc = False
    else:
        ans[i] = 0
        if trdec[i] == 0:
            now_inc = True
print("YES")
print(" ".join(str(x) for x in ans))