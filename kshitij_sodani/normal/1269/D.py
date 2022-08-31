n=int(input())
it=list(map(int,input().split()))
a=0
b=0
for i in range(n):
    if i%2==0:
        a+=it[i]//2
        b+=it[i]//2
        a+=it[i]%2
    else:
        b+=it[i]//2
        a+=it[i]//2
        b+=it[i]%2
print(min(a,b))