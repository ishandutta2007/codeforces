def ou(x):
    x += 48
    print "+"*x+"."+"[-]"
x = eval(raw_input())
if x >= 100:
    ou(x / 100)
    ou(x % 100 / 10)
    ou(x % 10)
elif x >= 10:
    ou(x / 10)
    ou(x % 10)
else:
    ou(x)