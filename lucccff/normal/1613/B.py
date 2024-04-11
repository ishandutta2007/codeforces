t = int(input())
while t > 0 :
    t -= 1
    n = int(input())
    a = list(map(int,input().split()))
    a.sort()
    i = n // 2
    while i > 0 :
        print(a[i],a[0])
        i -= 1