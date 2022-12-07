n = int(input())
l = list(map(int,input().split()))
a = []
for i in range(n):
    a.append(max(l))
    k = l.index(max(l))
    del l[k]
a.reverse()
for j in range(n):
    if j < n - 1:
        print(a[j], end = " ")
    else:
        print(a[j])