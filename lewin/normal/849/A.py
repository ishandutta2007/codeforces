n = int(raw_input())
arr = map(int, raw_input().split())
print (arr[0] % 2 == 1 and arr[n-1] % 2 == 1 and n % 2 == 1) * "YES" or "NO"