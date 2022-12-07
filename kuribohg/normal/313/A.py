n = int(input())
if n >= 0:
    print(int(n))
else:
    if n > -100 and (-n) % 10 == 0:
        print(int(0))
    else:
        a = []
        k = len(str(n))
        for i in range(k - 2,k):
            l = list(str(n))
            del l[i]
            s = int("".join(l))
            a.append(s)
        print(int(max(a)))