is_prime = [True] * (10**6 + 1);

for i in xrange(2,10**6+1):
    if is_prime[i]:
        for j in xrange(2 * i, 10**6 + 1, i):
            is_prime[j] = False

def rev(x):
    result = 0
    while x > 0:
        result = 10 * result + (x % 10)
        x /= 10
    return result

d = int(raw_input())
for i in xrange(2,10**6 * 2 +1):
    if is_prime[i]:
        r = rev(i)
        if r != i and is_prime[r]:
            d -= 1
            if d == 0:
                print i
                quit()