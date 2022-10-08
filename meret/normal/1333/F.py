n = int(input())

min_div = [i for i in range(n + 1)]

for i in range(2, n + 1):
    if i * i > n:
        break
    for j in range(2 * i, n + 1, i):
        if min_div[j] == j:
            min_div[j] = i

cost = [i // min_div[i] for i in range(1, n + 1)]
cost.sort()
for c in cost[1:]:
    print(c, end=' ')
print()