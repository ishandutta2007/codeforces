n=input()
a=map(int,raw_input().split())
s=['chest','biceps','back']
p=[0]*3
for i in range(n):
    p[i%3]+=a[i]
for i in range(3):
    if p[i]==max(p):
        print s[i]