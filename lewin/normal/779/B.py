a = raw_input().split()
s = a[0]
k = int(a[1])
if s.count("0") < k:
    print len(s)-1
else:
    ans = 0
    for i in range(len(s)-1,-1,-1):
        if k == 0:
            break
        if s[i] != '0':
            ans += 1
        else:
            k -= 1
    print ans