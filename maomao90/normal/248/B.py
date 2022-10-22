n = int(input())
cur = 10 ** (n - 1)
correct = False
for count in range(cur, 10 ** n):
    if (count % 210 == 0):
        print(count)
        correct = True
        break
if (not correct):
    print("-1")