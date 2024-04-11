for _ in range(int(input())):
    n, m = map(int, input().split())
    tiles = [[list(map(int, input().split())) for _ in range(2)] for _ in range(n)]
    if m % 2 == 1:
        print('NO')
        continue
    if any(t[1][0] == t[0][1] for t in tiles):
        print('YES')
    else:
        print('NO')