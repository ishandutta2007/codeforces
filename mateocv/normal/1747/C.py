t = int(input())

for _ in range(t):
	n = int(input())
	a = list(map(int, input().split(' ')))
	a[0] -= 1
	mini = min(a[1:])
	if(mini <= a[0]):
		print("Alice")
	else:
		print("Bob")