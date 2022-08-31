t = int(input())
for x in range(t):
 x,y=[int(a) for a in input().split(' ')]
 if (x-1) * (y-1) <= 1:
  print("YES")
 else:
  print("NO")