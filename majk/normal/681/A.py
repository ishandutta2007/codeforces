N=int(input())
ok=False
for _ in range(N):
    a,b,c=input().split()
    b=int(b)
    c=int(c)
    ok |= b >= 2400 and c > b
print("YES" if ok else "NO")