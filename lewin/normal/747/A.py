n = int(raw_input())

a,b = 1,n
for i in range(1,n+1):
	if i*i > n:
		break
	if n % i == 0:
		if n/i - i < b-a:
			a,b = i,n/i
print a,b