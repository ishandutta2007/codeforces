x=int(input())
s={x:1}
a=0
while True:
    a+=1
    x+=1
    while x%10==0:
        x=x//10
    try:
        aa=s[x]
        a-=1
        break
    except:
        pass
    
    s[x]=1
print(len(s.keys()))