from math import ceil
n = int(input())
x = input().split()
a = x.count("4")
b = x.count("3")
c = x.count("2")
d = x.count("1")
ans = a + b + ceil(c/2)
t = b + 2 * (c%2)
if d <= t:
    ans = ans
else:
    ans = ans + ceil((d - t)/4)
print(int(ans))