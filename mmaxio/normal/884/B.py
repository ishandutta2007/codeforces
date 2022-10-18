r = lambda: map(int, input().split())
n, x = r()
print("YES" if sum(r()) + n - 1 == x else "NO")