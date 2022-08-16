n=input()
a=[0]+map(int,raw_input().split())
for i in range(n):
    a[i+1]^=a[i]
print max(x^y for x in a for y in a)