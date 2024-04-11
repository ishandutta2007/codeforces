for _ in range(int(input())):
    n, k = [int(x) for x in (input().split())]
    a = [int(x) for x in input().split()]
    INF = - (10 ** 15)
    dp = [INF] * 33
    dp[0] = 0
    ans = 0
    
    for i in range(n):
        ndp = [INF] * 33
        for j in range(len(dp)):
            if dp[j] == INF: continue
            ndp[j] = max(ndp[j], dp[j] - k + (a[i] >> j))
            if j + 1 < len(dp) : ndp[j + 1] = max(ndp[j + 1], (a[i] >> (j + 1)) +dp[j])
        dp = ndp              
        ans = max(ans, dp[30])
  

    print(max(ans, max(dp)))