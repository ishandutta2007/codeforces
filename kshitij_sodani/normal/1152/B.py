x=int(input())
ind=0
a=list(bin(x)[2:])
s=[]
while True:
    try:
        ind=a.index('0')
    except:
        print(len(s)*2)
        break
    s.append(str(len(a)-ind))
    x=x^(2**(len(a)-ind)-1)
    a=list(bin(x)[2:])
    try:
        ind=a.index('0')
    except:
        print(len(s)*2-1)
        break
    x+=1
    a=list(bin(x)[2:])
if s!=[]:
    print(' '.join(s))