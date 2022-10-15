def even_sum(n):
    return n * (n + 1)

def odd_sum(n):
    return even_sum(n) - n

def sum(n):
    cnt = 0
    m = n
    while m != 0:
        cnt += 1
        m >>= 1
    if cnt % 2 == 0:
        odds = (4 ** (cnt // 2) - 1) // 3
        evens = n - odds
    else:
        evens = 2 * (4 ** (cnt // 2) - 1) // 3
        odds = n - evens
    return even_sum(evens) + odd_sum(odds)

l, r = map(int, input().split())
print((sum(r) - sum(l - 1)) % (10 ** 9 + 7))