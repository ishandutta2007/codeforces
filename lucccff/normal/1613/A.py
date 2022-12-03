t = int(input())
while t > 0:
    t -= 1
    a , b = map(int,input().split())
    c , d = map(int,input().split())
    if a == 0:
        if c != 0:
            print("<")
        else :
            print("=")
        continue
    if c == 0 :
        print(">")
        continue
    if b > d + 6 :
        print(">")
    else:
        if d > b + 6 :
            print("<")
        else :
            if d > b:
                i = d - b
                while i > 0 :
                    c *= 10
                    i -= 1
            if d < b :
                i = b - d
                while i > 0 :
                    a *= 10
                    i -= 1
            if a > c :
                print(">")
            else :
                if a < c :
                    print("<")
                else :
                    print("=")