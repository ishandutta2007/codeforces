n = int(raw_input())
curtime = 0
for i in range(n):
    s,d = map(int, raw_input().split())
    if curtime < s:
        curtime = s
        continue
    off = (curtime - s) % d
    curtime += d - off
print curtime