s = input()
for i in range(2, len(s)):
    if ord(s[i]) + ord('A') != ord(s[i - 1]) + ord(s[i - 2]) and ord(s[i]) + ord('A') + 26 != ord(s[i - 1]) + ord(s[i - 2]):
        print('NO')
        break
else:
    print('YES')