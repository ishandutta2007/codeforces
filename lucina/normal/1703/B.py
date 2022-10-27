for _ in range(int(input())):
    l = []
    ans = 0
    input()
    for x in input():
        if x in l:
            ans += 1
        else:
            ans += 2
            l.append(x)
    print(ans)