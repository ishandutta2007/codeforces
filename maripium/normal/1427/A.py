tt = int(input())
for tc in range(tt):
    n = int(input())
    a = list(map(int, input().split()))
    s = sum(a)
    if s == 0:
        print("NO")
    elif s > 0:
        print("YES")
        a.sort()
        a.reverse()
        print(*a)
    else: 
        print("YES")
        a.sort()
        print(*a)