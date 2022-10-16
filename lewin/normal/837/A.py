n = int(raw_input())
x = raw_input().split()
print max(sum(c.isupper() for c in w) for w in x)