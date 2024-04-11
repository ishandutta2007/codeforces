import sys
n = int(raw_input())

arr = map(int, raw_input().split())

m = max(arr)
x1 = -1
x2 = -1
for i in range(n):
    if arr[i] == m:
        x2 = i
        if x1 == -1:
            x1 = i

for i in range(x1,x2+1):
    if arr[i] != m:
        print "NO"
        sys.exit(0)

for i in range(x1):
    if arr[i] >= arr[i+1]:
        print "NO"
        sys.exit(0)

for i in range(x2, n-1):
    if arr[i] <= arr[i+1]:
        print "NO"
        sys.exit(0)

print "YES"