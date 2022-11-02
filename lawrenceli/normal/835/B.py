k = int(raw_input())
n = map(int, raw_input())
n.sort()
k -= sum(n)
ans = 0
i = 0
while i < len(n) and k > 0:
    ans += 1
    k -= 9 - n[i]
    i += 1

assert k <= 0
print ans