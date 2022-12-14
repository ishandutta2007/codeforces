test = int(input())
for i in range (0, test):
    s = input()
    if len(s) <= 10 :
        print(s)
    else :
        ss = s[0]
        ss += '%d' %(len(s) - 2)
        ss += s[len(s) - 1]
        print(ss)