T = int(input())
while T > 0:
    T -= 1
    n = input()
    tot = 0
    ans = False
    for i in range(1, 10000):
        for j in range(4):
            w = str(i) * (j + 1)
            tot += len(w)
            if n == w:
                ans = True
                break
        if ans:
            break
    print(tot)