n = int(input())
a = list(map(int, input().split()))
s = sum(a)
s1 = 0
i = 0
while s1 * 2 < s:
    s1 += a[i]
    i += 1
print(i)