n=int(input())
it=list(map(int,input().split()))
m=int(input())
its=list(map(int,input().split()))
st=False
for i in it:
    for j in its:
        if i+j not in it and i+j not in its:
            a=i
            b=j
            st=True
    if st:
        break
print(a,b)