n, s = map(int, input().split())
if n*2 <= s:
    print("YES")
    a = [2]*(n-1)
    a.append(s-2*(n-1))
    print(*a)
    print(1)
else:
    print("NO")