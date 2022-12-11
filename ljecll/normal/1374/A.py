TC = int(input())

for tc in range(TC):
    a, b, c = map(int, input().split())
    #it's <= c and it's b mod a
    #a*k+b <= c
    #a*k <= c - b
    print(((c - b) // a) * a + b)