ans = 0.0
p = 1.0
id = input().split()
a, b, c, d = int(id[0]), int(id[1]), int(id[2]), int(id[3])
for i in range( 100000 ):
	ans += p * a / b
	p *= (1.0 - a / b)
	p *= (1.0 - c / d)
print( ans )