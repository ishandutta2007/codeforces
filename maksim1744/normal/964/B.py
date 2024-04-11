n, a, b, c, t = map(int, input().split())
tim = list(map(int, input().split()))
if c > b:
    s = sum([a + (t - ti) * (c - b) for ti in tim])
else:
    s = a * n
print(s)