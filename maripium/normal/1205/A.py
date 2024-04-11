n = int(input())
ans = [0 for a in range (n)]
if n % 2 == 0:
   print("NO")
else:
   print("YES")
   l = []
   r = []
   for i in range(0, n - 1, 2) :
      l.append(2 * i);
      l.append(2 * i + 3)
      r.append(2 * i + 1)
      r.append(2 * i + 2)
   l.append(2 * n - 2)
   r.append(2 * n - 1)
   for x in l :
      print(x + 1, end = ' ')
   for x in r :
      print(x + 1, end = ' ')