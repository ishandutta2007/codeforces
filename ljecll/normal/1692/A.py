tc = int(input())
for i in range(tc):
    a, b, c, d = map(int, input().split())
    ans = (int) (b > a) + (int) (c > a) + (int) (d > a)
    print(ans)