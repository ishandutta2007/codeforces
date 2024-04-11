n=input()
a=map(int,raw_input().split())
s=(sum(a)+1)/2
t=0
for i in xrange(n):
    t+=a[i]
    if t>=s:
        print i+1
        break