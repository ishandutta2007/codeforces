n,x = map(int, raw_input().split())
a = map(int, raw_input().split())
ans = a.count(x)
for i in range(x):
    if i not in a:
        ans += 1
print ans