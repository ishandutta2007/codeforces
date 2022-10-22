n = int(input())
for _ in range(n):
    s = input()
    if len(s) > 10:
        s = s[0] + str(len(s) - 2) + s[-1]
    print(s)