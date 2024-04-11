n = int(input())

ret = 0
ways = 1
for i in range(1, 8):
    ways = ways * (n - i + 1) // i
    if i >= 5:
        ret += ways
        
print(ret)