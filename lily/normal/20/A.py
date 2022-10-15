a = input()
while True:
    b = a.replace('//', '/')
    if len(a) == len(b):
        break
    a = b
if a != '/' and a[-1] == '/':
    a = a[:-1]
print(a)