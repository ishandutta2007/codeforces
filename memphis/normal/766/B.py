import math

n=int(raw_input())
readin=raw_input().split()
c=[]
for i in readin:
    c.append(int(i))
c.sort()
for i in range(2,n):
    if c[i-2]+c[i-1]>c[i]:
        print "YES"
        exit()

print "NO"