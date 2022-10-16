import fractions

t, w, b = map(int, input().split())
t += 1

def gcd(a, b):
	while b > 0:
		a, b = b, a % b
	return a

def lcm(a, b):
	return a * b // gcd(a, b)

if w > b:
	w, b = b, w

l = lcm(w, b)

tie = t // l * w
tie += min(w, t % l)
tie -= 1

a = tie
b = t - 1
g = gcd(a, b)
a //= g
b //= g
print("%d/%d"%(a, b))