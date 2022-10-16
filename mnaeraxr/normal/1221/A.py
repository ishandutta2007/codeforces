t = int(input())

for _ in range(t):
 _ = input()
 L = [int(x) for x in input().split() if int(x) <= 2048]
 print("YES" if sum(L) >= 2048 else "NO")