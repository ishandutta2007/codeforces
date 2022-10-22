n = int(input())
a = [int(i) for i in input().split()]
q = set()
for x in a:
    if x not in q:
        q.add(x)
if len(q) > 3:
    print("NO")
elif len(q) < 3:
    print("YES")
else:
    x, y, z = q
    for it in range(3):
        if x > y :
            tmp = x
            x = y
            y = tmp
        if y > z :
            tmp = y
            y = z
            z = tmp
    if y - x == z - y:
        print("YES")
    else:
        print("NO")