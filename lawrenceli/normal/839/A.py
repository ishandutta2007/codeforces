n, k = map(int, raw_input().split())
a = list(map(int, raw_input().split()))
cur = 0
for i in range(len(a)):
    cur += a[i]
    num = min(8, cur)
    cur -= num
    k -= num
    if k <= 0:
        print i + 1
        quit()
print -1