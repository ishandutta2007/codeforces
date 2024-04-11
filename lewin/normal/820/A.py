c,v0,v1,a,l = map(int, raw_input().split())

rem = c
ans = 0
cspeed = v0
while rem > 0:
    rem += l
    rem = min(rem, c)
    rem -= cspeed
    cspeed += a
    cspeed = min(cspeed, v1)
    ans += 1
print ans