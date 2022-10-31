n, h = map(int,input().split())
a = list(map(int,input().split()))
print( sum(map(lambda x: 1 if x <= h else 2, a)) )