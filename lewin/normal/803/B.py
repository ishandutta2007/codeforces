n = int(raw_input())
arr = map(int, raw_input().split())
res = [n+1 for __ in range(n)]
lst = -n
for i in range(n):
	if arr[i] == 0:
		lst = i
	res[i] = i-lst

lst = 2*n
for i in range(n-1,-1,-1):
	if arr[i] == 0:
		lst = i
	res[i] = min(res[i], lst-i)

print " ".join(map(str,res))