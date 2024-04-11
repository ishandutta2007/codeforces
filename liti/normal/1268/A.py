n, k = map(int, input().split())
s = input()

num = s[:k]*(n//k) + s[:n%k]

print(n)
if s <= num:
    print(num)
else:
    v = str(int(s[:k]) + 1)
    num  = v * (n//k)+ v[:n%k]
    print(num)