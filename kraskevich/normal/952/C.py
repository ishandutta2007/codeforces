def is_good(xs):
    for i in range(1, len(xs)):
        if abs(xs[i] - xs[i - 1]) >= 2:
            return False
    return True


n = int(input())
xs = list(map(int, input().split()))
ok = is_good(xs) and is_good(list(sorted(xs)))
for i in range(n):
    pos = 0
    for j in range(n - i):
        if xs[j] > xs[pos]:
            pos = j
    val = xs[pos]
    xs.pop(pos)
    ok = ok and is_good(xs)
print('YES' if ok else 'NO')