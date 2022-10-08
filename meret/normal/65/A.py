t = list(map(int, input().split()))
f0 = 3
while t[f0] != 0:
    f0 = (f0 + 5) % 6
    if f0 == 3:
        break
if f0 % 2 == 0:
    print('Ron')
    exit()
num = t[1] * t[3] * t[5]
den = t[0] * t[2] * t[4]
if num > den:
    print('Ron')
else:
    print('Hermione')