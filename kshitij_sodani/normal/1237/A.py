n=int(input())
st=1
for i in range(n):
    a=int(input())
    if a%2==0:
        print(a//2)
        continue
    if a==0:
        print(0)
    if a<0:
        if st==1:
            print(a//2)
            st=0
        else:
            print(a//2+1)
            st=1
    if a>0:
        if st==1:
            print(a//2)
            st=0
        else:
            print(a//2+1)
            st=1