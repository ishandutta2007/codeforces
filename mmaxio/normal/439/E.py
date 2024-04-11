import itertools
import functools
import operator

N = 100001
P = 10**9 + 7

fact = [1]
for i in range(1, N):
	fact.append(fact[-1] * i % P)

inv = [0, 1]
for i in range(2, N):
	inv.append(P - P // i * inv[P % i] % P)
inv_fact = [1]
for i in range(1, N):
	inv_fact.append(inv_fact[-1] * inv[i] % P)

least_div = [-1] * N
primes = []

for p in range(2, N):
	if least_div[p] == -1:
		primes.append(p)
		least_div[p] = p
	ldiv = least_div[p]
	for mult in primes:
		mark = mult * p
		if (mult > ldiv) or (mark >= N):
			break
		least_div[mark] = mult

t = int(input())

def powerset(iterable):
    s = list(iterable)
    return itertools.chain.from_iterable(itertools.combinations(s, r) for r in range(len(s) + 1))

@functools.lru_cache(maxsize = None)
def factor(n):
	ret = []
	while n != 1:
		tmp = least_div[n]
		if not(ret and ret[-1] == tmp):
			ret.append(tmp)
		n //= tmp
	return ret

@functools.lru_cache(maxsize = None)
def solve(n, k):
	divs = factor(n)
	# print(divs)
	ret = 0
	for subset in powerset(divs):
		div = functools.reduce(operator.mul, subset, 1)
		# print(div, f(n // div, k))
		if n // div >= k:
			tmp = fact[n // div - 1] * inv_fact[n // div - k] % P * inv_fact[k - 1] % P
			ret += (-1 if len(subset) % 2 == 1 else 1) * tmp
			ret %= P
	return ret

for _ in range(t):
	n, k = map(int, input().split())
	print(solve(n, k))