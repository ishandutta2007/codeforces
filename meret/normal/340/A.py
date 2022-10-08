x,y,a,b = map(int, input().split())
g = 1
while g % x or g % y:
    g += 1
print(b // g - (a - 1) // g)