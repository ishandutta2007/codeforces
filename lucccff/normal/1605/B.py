t = int(input())
for x in range(t) :
    n = int(input())
    a = input()
    flag = True
    k = 0
    for p in a :
        if k > int(p) :
            flag = False
            break
        k = max(k,int(p))
    if flag :
        print(0)
        continue
    i = 0
    j = -1
    k = n
    while j < k :
        i += 1
        j += 1
        k -= 1
        while j < n and a[j] == '0' : j += 1
        while k >= 0 and a[k] == '1' : k -= 1
    print(1)
    print(2 * (i - 1),end=' ')
    j -= 1
    k += 1
    while k < n and a[k] == '1' : k += 1
    while j >= 0 and a[j] == '0' : j -= 1
    for i in range(j + 1) :
        if a[i] == '1' : print(i + 1,end=' ')
    for i in range(k,n) :
        if a[i] == '0' : print(i + 1,end=' ')
    print('')