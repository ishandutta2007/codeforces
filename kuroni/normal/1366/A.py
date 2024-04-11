t = int(input())
for i in range(t):
    a, b = [int(x) for x in input().split()]
    print(min((a + b) // 3, a, b))