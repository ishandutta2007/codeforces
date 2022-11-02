n = input()
ans = 0
for i in range(n): 
    ans += 1 if raw_input().count('+') > 0 else -1
print ans