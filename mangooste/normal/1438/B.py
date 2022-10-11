for _ in range(int(input())):
    n = int(input())
    b = list(map(int, input().split()))
    b.sort()
    ok = False
    for i in range(1, n):
        ok |= b[i] == b[i - 1]
    print("YES" if ok else "NO")