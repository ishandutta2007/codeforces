n = input()
ans = 0
for i in range(n): ans += 1 if map(int,raw_input().split()).count(1) > 1 else 0
print ans