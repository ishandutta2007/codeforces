t=int(input())
for i in range(t):
    n=int(input())
    x=int(str(n)[0])
    tot=0
    for i in range(len(str(n))-1):
        tot+=9
    for i in range(1,x):
        
        tot+=1
    if int(str(x)*len(str(n)))<=n:
        tot+=1
    print(tot)