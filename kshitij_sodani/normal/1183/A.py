a=int(input())
ma=a
for i in range(a,a+1000):
    x=list(str(i))
    x=list(map(int,x))
    if sum(x)%4==0:
        ma=i
        break
print(ma)