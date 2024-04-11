a,b=map(int,input().split())
if a==b:
    print(a*10+1,b*10+2)
elif a==9 and b==1:
    print(9,10)
elif (b-a)==1:
    print(a*10+9,b*10)
else:
    print(-1)