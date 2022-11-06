from fractions import gcd
lst = map(int, raw_input().split())
t = lst[0]
a = lst[1]
b = lst[2]
g = gcd(a,b)
assert a % g == 0 and b % g == 0
lcm = (a/g)*b
num = (t/lcm) * min(a,b) - 1
k = (t/lcm)*lcm
assert k <= t
num += min(k+min(a,b)-1, t) - (k-1)
denom = t
h = gcd(num, denom)
num = num/h
denom = denom/h
s = str(num)+'/'+str(denom)
print s