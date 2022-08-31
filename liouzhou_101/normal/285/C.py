n=input()
a=sorted(map(int,raw_input().split()))
p=0
for i in range(n):p+=abs(a[i]-i-1)
print p