test = int(input())
for i in range(test):
    n = int(input())
    cnt = [1 for x in range(n+1)]
    num = n
    pos = n - 1
    ans = []
    p = list(map(int, input().split(' ')))
    while pos >= 0:
        while cnt[num] == 0:
            num -= 1
        lst = pos
        while p[pos] != num:
            pos -= 1
        for x in range (pos, lst+1):
            ans.append(p[x])
            cnt[p[x]] -= 1
        pos -= 1
    print(*ans)