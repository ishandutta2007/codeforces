n = int(input())
path = []
for i in range(0,n):
    c = input().split()
    if c[0] == 'cd':
        s = c[1].split('/')
        if s[0] == '':
            path.clear()
            s.pop(0)
        for d in s:
            if d == '..':
                path.pop()
            else:
                path.append(d)
    else:
        print('/', end='')
        for d in path:
            print(d, '/', sep='', end='')
        print()