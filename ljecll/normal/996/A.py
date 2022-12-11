n = int(input())

ans = 0
cur = 0

cur = n // 100
ans = ans + cur
n = n - 100 * cur

cur = n // 20
ans = ans + cur
n = n - 20 * cur

cur = n // 10
ans = ans + cur
n = n - 10 * cur

cur = n // 5
ans = ans + cur
n = n - 5 * cur

cur = n // 1
ans = ans + cur
n = n - 1 * cur

print(ans)