a = [0, 1, 5, -1, -1, 2, -1, -1, 8, -1]
test = int(input())
def check(x, y, h, m):
    if a[x // 10] == -1 or a[x % 10] == -1 or a[y // 10] == -1 or a[y % 10] == -1 :
        return 0
    if a[x % 10] * 10 + a[x // 10] >= m or a[y % 10] * 10 + a[y // 10] >= h :
        return 0
    return 1
def pnt(x, y):
    res=''
    if x < 10 :
        res += '0'
    res += str(x)
    res += ':'
    if y < 10 :
        res += '0'
    res += str(y)
    print(res)
    return 0
for i in range(test):
    h, m = map(int, input().split(' '))
    s = input()
    arr = s.split(':')
    x = int(arr[0])
    y = int(arr[1])
    while True:
        if check(x, y, h, m) == 1 :
            pnt(x, y)
            break
        else :
            y += 1
            if y >= m :
                y -= m
                x += 1
                if x >= h :
                    x -= h