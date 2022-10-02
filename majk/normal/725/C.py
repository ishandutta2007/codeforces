from collections import *

S=list(input())
D=defaultdict(list)
for i in range(27):
    D[S[i]].append(i)

ok = False
for k,v in D.items():
    if v[-1] - v[0] > 1:
        l = v[-1] - v[0]
        del S[v[-1]]
        A=[' ']*13
        B=[' ']*13
        for i in range(0, 13):
            A[i]=S[(-i+v[0]+(l-1)//2)%26]
        for i in range(0, 13):
            B[i]=S[(v[0]+(l-1)//2+1+i)%26]
        print(''.join(A))
        print(''.join(B))
        ok = True
        break

if not ok:
    print("Impossible")