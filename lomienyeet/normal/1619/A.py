for _ in range(int(input())):
    s=input()
    if(s[len(s)//2:]!=s[:len(s)//2]):
        print("NO")
    else:
        print("YES")