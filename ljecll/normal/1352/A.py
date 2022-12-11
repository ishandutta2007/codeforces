TC = int(input())

def solve(n):
    if (n == 0):
        return []
    res = solve(n // 10)
    res = [x * 10 for x in res]
    if (n % 10):
        res.append(n % 10)
    return res

for tc in range(TC):
    c = int(input())
    res = solve(c)
    print(len(res))
    for x in res:
        print(x, end = " ")
    print()