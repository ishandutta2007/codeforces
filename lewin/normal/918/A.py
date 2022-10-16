n = int(raw_input())
s = ['o' for __ in xrange(n)]
a = 1
b = 1
while b <= n:
  s[b-1] = 'O'
  a,b = b,a+b
print "".join(s)