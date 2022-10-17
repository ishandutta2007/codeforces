def solve():
    d = [[int(x) for x in raw_input().split()] for _ in range(3)]
    for i in range(2):
        for j in range(2):
            for k in range(2):
                if d[0][i] >= d[1][j] + d[2][k] and d[0][1-i] >= max(d[1][1-j], d[2][1-k]):
                    return True
    return False

print("YES" if solve() else "NO")