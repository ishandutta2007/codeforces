n, k = map(int, raw_input().split())
n1 = 0
n2 = n * 2
n4 = n
a = list(map(int, raw_input().split()))

for i in range(len(a)):
    while a[i] >= 4 and n4 > 0:
        a[i], n4 = a[i] - 4, n4 - 1
    while a[i] >= 4 and n2 > 0:
        a[i], n2 = a[i] - 2, n2 - 1
    if a[i] >= 4:
        print "NO"
        quit()

for i in range(len(a)):
    while a[i] >= 2 and n4 > 0:
        a[i], n4, n1 = a[i] - 2, n4 - 1, n1 + 1
    while a[i] >= 2 and n2 > 0:
        a[i], n2 = a[i] - 2, n2 - 1
    while a[i] >= 2 and n1 > 0:
        a[i], n1 = a[i] - 1, n1 - 1
    if a[i] >= 2:
        print "NO"
        quit()

num = n4 * 2 + n2 + n1
for i in range(len(a)):
    while a[i] > 0 and num > 0:
        a[i], num = a[i] - 1, num - 1
    if a[i] > 0:
        print "NO"
        quit()

print "YES"