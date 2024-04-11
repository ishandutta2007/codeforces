from itertools import chain, combinations

def powerset(iterable):
    xs = list(iterable)
    return chain.from_iterable(combinations(xs,n) for n in range(len(xs)+1))

R=""
S=input()
for s in powerset(S):
    t = ''.join(s)
    u = ''.join(reversed(s))
    if t==u and t>R:
        R = t
print(R)