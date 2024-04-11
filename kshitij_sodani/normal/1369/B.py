#list(map(int,input().split()))
t=int(input())
for _ in range(t):
    n=int(input())
    s=input()
    co=0
    for i in range(n):
        if(s[i]=='1'):
            break
        print('0',end="")
        co+=1
    ind=n
    
    for i in range(n-1,-1,-1):
        if(s[i]=='0'):
            break
        ind=i
    if(co-1<ind-1):
        print('0',end="")
    for i in range(ind,n):
        print('1',end="")
    print()