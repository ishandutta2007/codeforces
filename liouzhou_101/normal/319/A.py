x=raw_input()
n=len(x)
p=0
for i in range(n):
    if x[i]=='1':
        p+=2**i*4**(n-i-1);
print p%(10**9+7)