w = 86400
n,t = map(int, raw_input().split())
arr = map(int, raw_input().split())
day = 0
while t > 0:
    day += 1
    t -= w - arr[day-1]
print day