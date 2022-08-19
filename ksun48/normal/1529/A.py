t = int(input())
for _ in range(t):
 n = int(input())
 a = list(int(x) for x in input().split())
 print(n - len([x for x in a if x == min(a)]))