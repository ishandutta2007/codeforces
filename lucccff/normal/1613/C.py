t = int(input())
while t > 0 :
    t -= 1
    n , h = map(int,input().split())
    a = list(map(int,input().split()))
    l = 1
    r = int(1e18)
    while l < r :
        m = (l + r) // 2
        flag = True
        ans = m
        for x in range(n-1) :
            ans += min(a[x+1] - a[x] , m)
        if ans < h :
            l = m + 1
        else :
            r = m
    print(l)