S=input()
R=int(S[:-1])
C=S[-1]
T=((R-1)//4)*16+((R-1)%2)*7
if C=='f':
    T+=1
if C=='e':
    T+=2
if C=='d':
    T+=3
if C=='a':
    T+=4
if C=='b':
    T+=5
if C=='c':
    T+=6
print(T)