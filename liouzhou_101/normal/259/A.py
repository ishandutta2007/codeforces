for _ in range(8):
    a=raw_input()
    for i in range(7):
        if a[i]==a[i+1]:
            print "NO"
            exit()
print "YES"