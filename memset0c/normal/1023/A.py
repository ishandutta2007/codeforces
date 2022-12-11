input()
a = input()
b = input()

a = a.split('*')

# print(a)
# print([b[:len(a[0])], b[-len(a[1]):]])


if len(a) == 1:
    if a[0] == b:
        print('YES')
    else:
        print('NO')
else:
    if len(b) < len(a[0]) + len(a[1]) \
            or (a[0] != b[:len(a[0])] and len(a[0]) > 0) \
            or (a[1] != b[-len(a[1]):] and len(a[1]) > 0):
        print('NO')
    else:
        print('YES')