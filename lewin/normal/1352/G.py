t = int(input())
for __ in range(t):
    n = int(input())
    if n <= 3:
        print(-1)
    else:
        ps = [[2,4,1,3],[3,1,4,2,5],[1,4,2,5,3,6],[5,1,3,6,2,4,7]]
        ret = ps[n%4]
        for i in range((n%4) + 4, n, 4):
            ret.extend([i+2,i+4,i+1,i+3])
        print(" ".join(map(str, ret)))