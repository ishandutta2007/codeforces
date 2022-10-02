def is_leap(Y):
    return (Y%4==0) and (Y%100!=0 or Y%400==0)

def next(y,d,l):
    d += 1
    if l:
        d += 1
    d = d%7
    y += 1
    l = is_leap(y)
    return y,d,l
    
S=int(input())
L=is_leap(S)
y,d,l=next(S,0,L)
while d != 0 or l != L:
    y,d,l=next(y,d,l)
print(y)