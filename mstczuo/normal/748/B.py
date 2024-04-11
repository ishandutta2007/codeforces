a = raw_input()
b = raw_input()

d = dict(tuple(zip(a, b) + zip(b, a)))

try:
    for u in a + b:
        assert d[d[u]] == u
    for (u, v) in zip(a, b):
        assert d[u] == v 
        assert d[v] == u
    ans = filter(lambda (u,v): u < v, d.items())
    ans = map(lambda (u, v): u + ' ' + v, ans)
    print len(ans)
    print '\n'.join(ans)
except:
    print -1