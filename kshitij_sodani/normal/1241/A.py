t=int(input())
for _ in range(t):
    n=int(input())
    if n<4:
        print(4-n)
        continue
    if n%2==1:
        print(1)
    else:
        print(0)