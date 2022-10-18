dd = raw_input()
ans = 0
s = [int(dd[0]), int(dd[1]), int(dd[3]), int(dd[4])]
while s[0] != s[3] or s[1] != s[2]:
    ans += 1
    s[3] += 1
    if s[3] == 10:
        s[3] = 0
        s[2] += 1
        if s[2] == 6:
            s[2] = 0
            s[1] += 1
            if s[1] == 10:
                s[1] = 0
                s[0] += 1

            if s[0] * 10 + s[1] == 24:
                s[0] = 0
                s[1] = 0
                
    
print ans