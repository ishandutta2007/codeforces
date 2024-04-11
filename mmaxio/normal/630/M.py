n = (-int(input())) % 360

ret, opt = 4, 361
for i in range(4):
    x = (n+90*i)%360
    x = min(x, 360-x)
    if (x, i) < (opt, ret):
        opt, ret = x, i

print(ret)