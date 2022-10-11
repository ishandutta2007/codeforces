t = int(input())
for _ in range(t):
    n = int(input())
    a = str(input())
    s = (10 ** n - 1) if a[0] != '9' else (10 ** (n + 1) - 1) // 9
    print(s - int(a))