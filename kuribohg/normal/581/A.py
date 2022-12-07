a, b = map(int,input().split())
n = min(a, b)
k = abs(a - b) % 2
m = (abs(a - b) - k)/2
print(int(n),int(m))