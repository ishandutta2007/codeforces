n, m = map(int, input().split(' '))
arr = [[0 for x in range(m)] for y in range(n)]
cc = [0 for x in range(m)]
def calc(arr1, arr2):
    res = 0
    for i in range(m):
        res += (arr1[i] != arr2[i])
    return res
def check(a):
    for i in range(n):
        if calc(a, arr[i]) > 2 :
            return 0
    return 1
def check3(a,x):
    for i in range(m): 
        cc[i] = a[i]
    cc[x] = -1
    for i in range(n):
        if calc(cc, arr[i]) - (arr[i][x] != cc[x]) > 2 :
            return 0
    xx = -1
    for i in range(n): 
        if calc(cc, arr[i]) > 2 :
            if xx != -1 and arr[i][x] != xx :
                return 0
            xx = arr[i][x]
    if xx == -1 :
        cc[x] = 1
    else :
        cc[x] = xx
    return 1
def Out(arr):
    print("Yes")
    print(*arr)
def chk3(a, b):
    x = [0, 0, 0]
    cnt = 0
    for i in range(m):
        if a[i] != b[i] :
            x[cnt] = i
            cnt +=1
    nw = [0 for x in range(m)]
    for i in range(m):
        nw[i] = a[i]
    nw[x[0]] = b[x[0]]
    if check3(nw, x[1]):
        Out(cc)
        return 0
    if check3(nw, x[2]):
        Out(cc)
        return 0
    nw[x[0]] = a[x[0]]
    nw[x[1]] = b[x[1]]
    if check3(nw, x[0]):
        Out(cc)
        return 0
    if check3(nw, x[2]):
        Out(cc)
        return 0
    nw[x[1]] = a[x[1]]
    nw[x[2]] = b[x[2]]
    if check3(nw, x[0]):
        Out(cc)
        return 0
    if check3(nw, x[1]):
        Out(cc)
        return 0
    print("No")
    return 1

def chk4(a, b):
    x = [0, 0, 0, 0]
    cnt = 0
    for i in range(m):
        if a[i] != b[i] :
            x[cnt] = i
            cnt += 1
    nw = [0 for x in range(m)]
    for i in range(m):
        nw[i] = a[i]
    nw[x[0]] = b[x[0]]
    nw[x[1]] = b[x[1]]
    if check(nw):
        Out(nw)
        return 0
    nw[x[1]] = a[x[1]]
    nw[x[2]] = b[x[2]]
    if check(nw):
        Out(nw)
        return 0
    nw[x[2]] = a[x[2]]
    nw[x[3]] = b[x[3]]
    if check(nw):
        Out(nw)
        return 0
    nw[x[0]] = a[x[0]]
    nw[x[1]] = b[x[1]]
    if check(nw):
        Out(nw)
        return 0
    nw[x[3]] = a[x[3]]
    nw[x[2]] = b[x[2]]
    if check(nw):
        Out(nw)
        return 0
    nw[x[1]] = a[x[1]]
    nw[x[3]] = b[x[3]]
    if check(nw):
        Out(nw)
        return 0
    print("No")
    return 1

for i in range(n):
    arr[i] = list(map(int, input().split(' ')))
if check(arr[0]) :
    Out(arr[0])
else :
    flg = 0
    for i in range(1, n):
        if flg == 1 :
            break
        elif (calc(arr[0], arr[i])) == 4 :
            chk4(arr[0], arr[i])
            flg = 1
    if flg == 0 :
        for i in range(1, n):
            if flg == 1:
                break
            elif (calc(arr[0], arr[i])) == 3 :
                chk3(arr[0], arr[i])
                flg = 1
        if flg == 0:
            print("No")