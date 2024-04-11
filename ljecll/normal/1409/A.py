TC = int(input())

for tc in range(TC):
    a, b = map(int, input().split())
    delta = abs(a - b)
    print((delta + 9) // 10)