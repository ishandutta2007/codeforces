n = int(raw_input())
s = raw_input()

for letter in range(26):
    has = False
    for i in s:
        if i == chr(ord('a') + letter) or i == chr(ord('A') + letter):
            has = True
    if not has:
        print 'NO'
        exit()


print 'YES'