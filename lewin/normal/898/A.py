n = int(raw_input())
x1 = n
x2 = n
while x1%10 !=0 and x2%10 != 0:
    x1 -= 1
    x2 += 1
if x1 % 10 == 0:
    print x1
else:
    print x2