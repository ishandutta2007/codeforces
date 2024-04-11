a,b = map(int, raw_input().split())
x,y,z = map(int, raw_input().split())

na = 2*x + y
nb = y + 3 * z

print max(na-a,0) + max(nb-b,0)