x,y,n=map(int,raw_input().split())
a,b=2**99,1
for i in range(1,n+1):
    p=x*i//y
    for j in range(p,p+2):
        if abs(x*b-y*a)*i>abs(x*i-y*j)*b:
            a,b=j,i
print str(a)+"/"+str(b)