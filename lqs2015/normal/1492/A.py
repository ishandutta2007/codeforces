test = int(input())
for i in range(test):
    p, a, b, c = map(int, input().split(' '))
    print(min((a - p % a) % a,((b - p % b) % b),((c - p % c) % c)))