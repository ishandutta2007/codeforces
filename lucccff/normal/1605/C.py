t = int(input())
for x in range(t) :
    n = int(input())
    s = input()
    i = 0
    mx = 5
    while i < n and s[i] != 'a' :
        i += 1
    i += 1
    while i < n :
        k = i
        l = 0
        m = 0
        while k < n and s[k] != 'a' :
            if s[k] == 'b' :
                l += 1
            else :
                m += 1
            k += 1
        if l < 2 and m < 2 and k < n :
            mx = min(l + m + 2,mx)
        i = k + 1
    if mx == 5 :
        flag = True
        for i in range(n-6) :
            if s[i] == 'a' and s[i+1] == 'b' and s[i+2] == 'b' and s[i+3] == 'a' and s[i+4] == 'c' and s[i+5] == 'c' and s[i+6] == 'a' or s[i] == 'a' and s[i+1] == 'c' and s[i+2] == 'c' and s[i+3] == 'a' and s[i+4] == 'b' and s[i+5] == 'b' and s[i+6] == 'a' :
                flag = False
                break
        if flag :
            print(-1)
        else :
            print(7)
    else :
        print(mx)