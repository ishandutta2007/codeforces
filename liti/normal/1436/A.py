t = int(input())

while t > 0:
    t -= 1
    n, m = map(int, input().split())
    a = map(int, input().split())
    print( "YES" if sum(a) == m else "NO" )