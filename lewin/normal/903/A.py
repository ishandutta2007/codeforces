
def f(x):
  return any(i * 3 <= x and (x - i * 3) % 7 == 0 for i in range(x))
print "\n".join([f(int(raw_input())) * "YES" or "NO" for __ in xrange(int(raw_input()))])