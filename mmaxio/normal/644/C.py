n = int(input())

d = dict()

for _ in range(n):
    s = input()
    slash = s.find('/', 7)
    if slash == -1:
        slash = len(s)
    host = s[:slash]
    query = s[slash:]
    d.setdefault(host, set()).add(query)
    
d1 = dict()
for k, v in d.items():
    f = frozenset(v)
    d1.setdefault(f, set()).add(k)
    
res = {k: v for k, v in d1.items() if len(v) > 1}
print(len(res))
for block in res.values():
    print(' '.join(block))