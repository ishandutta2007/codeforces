n = int( input().split()[0] )
answer = 0
for i in range(0, n):
	task = input().split()
	a = int( task[0] )
	b = int( task[1] )
	c = int( task[2] )
	if a + b + c >= 2:
		answer += 1
print( answer )