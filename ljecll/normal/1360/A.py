TC = int(input())

for tc in range(TC):
    a, b = map(int, input().split())
    res = min(max(b, 2 * a), max(a, 2 * b))
    print(res * res)