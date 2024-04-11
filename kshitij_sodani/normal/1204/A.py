s=input()
if s=="1":
    print(0)

elif s[1:]=="0"*len(s[1:]) and len(s)%2==1:
    print((len(s)+1)//2-1)
else:
    print((len(s)+1)//2)