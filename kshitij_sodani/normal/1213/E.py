n=int(input())
s=input()
t=input()
for i in "abc":
    if i not in s and i not in t:
        l=i

if t[0]==t[1]:
    s,t=t,s
print("YES")
if s[0]==s[1]:

    if t[0]==t[1]:
        print("abc"*n)
    elif s[0] in t:
        x=t[0]
        if x in s:
            x=t[1]
        print((s[0]+l)*n+x*n)
    else:
        print((t[0]+s[0]+t[1])*n)
elif s==t:
    print((s[0]+l+s[1])*n)
elif s[-1::-1]==t:
    print((s[0]+l)*n+s[1]*n)
elif s[1]==t[0]:
    print((s[1]+s[0]+t[1])*n)
    
elif t[1]==s[0]:
    print((t[0]+s[1]+t[1])*n)
elif s[1]==t[1]:
    print(s[1]*n+s[0]*n+t[0]*n)
elif s[0]==t[0]:
    print(s[1]*n+t[1]*n+t[0]*n)