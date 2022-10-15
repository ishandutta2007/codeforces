T = int(input())
while T > 0:
    T -= 1
    n, m = map(int, input().split())
    print("Burenka" if (n + m) % 2 == 1 else "Tonya")