X = set()
Y = set()
dots = []
for i in range(8):
    x,y = map(int,raw_input().split())
    X.add(x)
    Y.add(y)
    dots.append((x,y))
if len(X) != 3 or len(Y) != 3:
    print 'ugly'
    exit()
X = sorted(list(X)); Y = sorted(list(Y))
for i in range(3):
    for j in range(3):
        if (i,j) == (1,1):
            continue
        if not (X[i],Y[j]) in dots:
            print 'ugly'
            exit()
print 'respectable'