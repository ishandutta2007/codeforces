x = input()
i = 0
m = "0000000"
n = "1111111"
k = 0
while i <= len(x) - 6:
    if x[i : i + 7] == m or x[i : i + 7] == n:
        k = k + 1
    else:
        k = k
    i = i + 1
    if i > len(x) - 6:
        break
if k == 0:
    print("NO")
else:
    print("YES")