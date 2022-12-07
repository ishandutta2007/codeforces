n, m = map(int,input().split())
l = list(map(int,input().split()))
z = 0
for i in range(m):
    if i == 0:
        z += l[i] - 1
    else:
        if l[i] < l[i - 1]:
            z += n + l[i] - l[i - 1]
        else:
            z += l[i] - l[i - 1]
print(int(z))