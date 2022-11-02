n = int(input()) + 2
a = [0] + list(map(int, input().split())) + [1001]

ans = 0
i = 0
while i < n:
    j = i
    while j < n and a[i] + j - i == a[j]:
        j += 1
    ans = max(ans, j-i-2)
    i = j

print(ans)