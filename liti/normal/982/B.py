n = int(input())
w = list(map(int, input().split()))
a = [ (w[i], i+1) for i in range(n) ]
avail = []

a.sort()

s = input()

tail = 0
for x in s:
    if x == '0':
        print( a[tail][1] , end=' ' )
        avail.append(tail)
        tail += 1
    else:
        v = avail.pop()
        print( a[v][1], end=' ' )