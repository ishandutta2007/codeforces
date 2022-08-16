n=input()
a=map(int,raw_input().split())
x=n+1
p=0
for i in range(n):
    if (a[-i-1]>x):
        p=n-i
        break
    x=min(x,a[-i-1])
print p