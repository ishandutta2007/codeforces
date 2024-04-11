n,p,f,g,h=input(),998244353,0,-2,1
for i in range(1,n):f,g,h=((i+2)*f-i*g)%p,f,h*(i+1)%p
print(f*n+h*n*(h*n+4-3*n)/2+p**9)%p