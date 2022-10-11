input()
a = list(map(int, input().split()))
l, r = list(map(int, input().split()))
print(sum(a[l - 1 : r - 1]))