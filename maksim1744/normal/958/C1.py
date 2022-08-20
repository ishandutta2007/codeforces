n, p = map(int, input().split())
a = list(map(int, input().split()))
a = [c % p for c in a]
s = sum(a)
sp = s % p
if sp == s or sp + 1 == p:
    print(sp)
else:
    print(sp + p)