n = int(input())
k = ["++X","+X+","X++"]
a = 0
for i in range(n):
    t = str(input())
    if t in k:
        a = a + 1
    else:
        a = a - 1
print(int(a))