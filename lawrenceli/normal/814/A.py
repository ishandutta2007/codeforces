n, k = map(int, raw_input().split())
a = list(map(int, raw_input().split()))
b = list(map(int, raw_input().split()))
b.sort()
b.reverse()
p = 0
for i in range(len(a)):
    if (a[i] == 0):
        a[i] = b[p]
        p += 1
for i in range(len(a) - 1):
    if a[i] >= a[i + 1]:
        print "Yes"
        quit()
print "No"