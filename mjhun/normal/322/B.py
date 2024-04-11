a,b,c=map(int,raw_input().split())
r=0
for i in range(min(3,a+1,b+1,c+1)):
    r=max(r,i+(a-i)/3+(b-i)/3+(c-i)/3)
print r