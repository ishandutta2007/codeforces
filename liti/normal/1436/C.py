from math import comb, factorial

mod = 10**9 + 7

n, x, pos = map(int, input().split())

lt = 0
gt = 0

left = 0
right = n

while left < right:
    middle = (left + right) // 2

    if middle <= pos:
        if middle < pos:
            lt += 1
        left = middle + 1
    else:
        gt += 1
        right = middle


rem = factorial(n - 1 - lt - gt) % mod
lt = comb(x - 1, lt) % mod * factorial(lt)
gt = comb(n - x, gt) % mod * factorial(gt)

print( lt * gt % mod * rem % mod )