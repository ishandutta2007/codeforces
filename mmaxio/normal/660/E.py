P = 10**9 + 7

n, k = map(int, input().split())

print(n + 1 if k == 1 else (k * pow(2 * k - 1, n, P) - pow(k, n, P)) * pow(k - 1, P - 2, P) % P)