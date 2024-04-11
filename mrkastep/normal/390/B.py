n = int(input())
a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]
happiness = 0
for i in range(n):
    if (b[i] + 1) // 2 <= a[i] and b[i] > 1:
        happiness += (b[i] // 2) * ((b[i] + 1) // 2)
    else:
        happiness -= 1
print(happiness)