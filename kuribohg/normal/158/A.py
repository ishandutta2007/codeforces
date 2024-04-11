n, k = map(int,input().split())
x = input()
l = [int(n) for n in x.split()]
i = 0
while i <= n - 1:
    if l[i] > 0:
        if l[i] >= l[k - 1]:
            i = i + 1
        else :
            break
    else :
        break
print(int(i))