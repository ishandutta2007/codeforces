t = int(input())

for _ in range(t):
    n = int(input())
    p = list(map(int, input().split()))
    
    segments = []
    max_so_far = 0
    segment_len = 0
    for x in p:
        if x > max_so_far:
            if segment_len > 0:
                segments.append(segment_len)
            segment_len = 1
            max_so_far = x
        else:
            segment_len += 1
    if segment_len > 0:
        segments.append(segment_len)
    
    dp = [False] * (n + 1)
    dp[0] = True
    
    for segment_len in segments:
        for i in range(n, segment_len - 1, -1):
            if dp[i - segment_len]:
                dp[i] = True
    
    if dp[n]:
        print("YES")
    else:
        print("NO")