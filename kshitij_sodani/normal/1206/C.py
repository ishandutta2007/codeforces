n=int(input())
if n%2==0:
    print("NO")
else:
    print("YES")
    it=[0]*(2*n)
    a=1
    for i in range(n):
        if i%2==0:
            it[i]=a
            it[i+n]=a+1
        else:
            it[i]=a+1
            it[i+n]=a
        a+=2
    for i in it:
        print(i,end=" ")