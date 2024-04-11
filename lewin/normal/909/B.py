n = int(raw_input())

ans = 0
for i in range(n%2,n+1,2):
	ans += i
print ans