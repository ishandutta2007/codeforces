a = list(map(int, input().split()))

def bear(a):
	for x in set(a):
		if a.count(x) >= 4:
			for _ in range(4):
				a.remove(x)
			return a[0] != a[1]
	return False

def eleph(a):
	for x in set(a):
		if a.count(x) >= 4:
			for _ in range(4):
				a.remove(x)
			return a[0] == a[1]
	return False	

if bear(a[:]):
	print('Bear')
elif eleph(a[:]):
	print ('Elephant')
else:
	print ('Alien')