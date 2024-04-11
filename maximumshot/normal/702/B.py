n = int(input())
cnt = dict()
res = 0
for x in input().split() :
    x = int(x)
    for pw in [2 ** j for j in range(32)] :
        if pw - x in cnt :
            res += cnt[pw - x]
    if x in cnt : cnt[x] += 1
    else : cnt[x] = 1
print(res)