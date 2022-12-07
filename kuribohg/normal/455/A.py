n = int(input())
l = [ [ 0 for x in range(2) ] for y in range(100000+10) ]
p = list(map(int,input().split()))
a = [0 for i in range(100000+10)]
for x in p:
    a[x] += 1
for i in range(1, 100000+1):
    l[i][0] = max(l[i-1][1], l[i-1][0]);
    l[i][1] = l[i-1][0] + i * a[i]
print(max(l[100000][0], l[100000][1]))