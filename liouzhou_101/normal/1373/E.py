tests = int(input())
INF = 10**20

for test in range(tests):
    n, w = map(int, input().split())
    res = INF
    for k in range(17):
        for d in range(10):
            tmp = 0
            for i in range(w+1):
                if d+i <= 9:
                    tmp += 9*k+d+i
                else:
                    tmp += 1+(d+i)-10
            if n >= tmp and (n-tmp)%(w+1) == 0:
                s = (n-tmp)//(w+1)
                if s <= 8:
                    prefix = str(s)
                else:
                    prefix = str((s-8)%9)+"9"*((s-8)//9)+"8"
                prefix += "9"*k
                prefix += str(d)
                x = int(prefix)
                if sum(sum(int(c) for c in str(x+i)) for i in range(w+1)) == n:
                    res = min(res, x)
    if res == INF: res = -1
    print(res)