n = int(input())
arr = list(map(int,input().split()))
pref = [0]*n
suf = [0]*n
 
pref[0] = arr[0]
for i in range(1, n): pref[i] = pref[i-1] | arr[i]
suf[-1] = arr[-1]
for i in range(n-2, -1, -1): suf[i] = suf[i+1] | arr[i]
 
maxind = -1
maxans = -1
for i in range(n):
    prefval = pref[i-1] if i else 0
    sufval = suf[i+1] if i<n-1 else 0
    val = arr[i] & ~(prefval | sufval)
    if val > maxans: maxind = i; maxans = val
print(arr[maxind], *arr[:maxind], *arr[maxind+1:])