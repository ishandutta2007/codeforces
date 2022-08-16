s=[raw_input()for i in range(4)]
for i in range(3):
    for j in range(3):
        if (s[i][j]=='.')+(s[i][j+1]=='.')+(s[i+1][j]=='.')+(s[i+1][j+1]=='.')!=2:
            print"YES"
            exit()
print"NO"