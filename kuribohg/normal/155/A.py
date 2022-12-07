n = int(input())
l = list(map(int,input().split()))
if n == 1:
    print(int(0))
else:
    if l[0] != l[1]:
        k = 1
    else:
        k = 0
    for i in range(2,n):
        if l[i] > max(l[0:i]) or l[i] < min(l[0:i]):
            k += 1
    print(int(k))