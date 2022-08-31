n = int(input())
a = list(map(int, input().split()))
print(max(0, n - a.count(max(a)) - a.count(min(a))))