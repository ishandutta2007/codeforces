def sol():
    s = input()
    for i in range(len(s)):
        if (2 * i > len(s) and s[0:i] == s[len(s) - i:len(s)]):
            print("YES\n", s[0:i], sep = "")
            return
    print("NO")
sol()