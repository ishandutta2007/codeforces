def isprime(i):
    if i < 2:
        return False

    if i == 2:
        return True

    if i % 2 == 0:
        return False

    j = 3
    while j * j <= i:
        if i % j == 0:
            return False
        j += 2
    return True

t = int(input())

while t > 0:
    t -= 1

    n = int(input())

    num = n
    while not isprime(num) or isprime(num-(n-1)):
        num += 1

    for i in range(n):
        print(' '.join(map(str, [1] * i + [num - (n-1)] + [1] * (n-i-1))))