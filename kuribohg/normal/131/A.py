x = input()
if len(x) > 1:
    if x.isupper() is True:
        print(x.lower())
    else:
        y = x[1:]
        if y.isupper() is True:
            print(x.swapcase())
        else:
            print(x)
else:
    if x.isupper() is True:
        print(x.lower())
    else:
        print(x.upper())