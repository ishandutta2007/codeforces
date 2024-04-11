from itertools import count

def f(n):
	least = 0
	ret = 0
	for x in count(1):
		least += 3 * x - 1
		if least > n:
			break
		if (n - least) % 3 == 0:
			ret += 1
	return ret

n = int(input())
print(f(n))