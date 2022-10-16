n = int(raw_input())
arr = map(int, raw_input().split())
print "YES" if ((n == 1 and arr[0] == 1) or (n > 1 and sum(arr) == n-1)) else "NO"