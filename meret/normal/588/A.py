n = int(raw_input())
result = 0
m = 100
for i in range(n):
    a, p = map(int, raw_input().split())
    if p < m:
       m = p
    result += a*m    
print result