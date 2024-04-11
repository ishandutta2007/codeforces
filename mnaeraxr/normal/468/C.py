a = int(input())
x = (45 * 18 * 10**17) % a
print(a - x, a - x + 10**18 - 1)