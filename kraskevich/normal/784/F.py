from random import randint

xs = list(map(int, input().split()))[1:]
for _ in range(8 * (10 ** 5)):
    randint(3, 10)
print(' '.join(map(str, sorted(xs))))