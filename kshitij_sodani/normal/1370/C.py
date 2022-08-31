#list(map(int,input().split()))
t=int(input())
for _ in range(t):
    n=int(input())
    if(n==1):
        print("FastestFinger")
        continue
    if(n==2):
        print("Ashishgup")
        continue

    if(n%2==1):
        print("Ashishgup")
        continue

    nn=n
    co=0
    while nn%2==0:
        nn//=2
        co+=1
    if(n==2**co):
        print("FastestFinger")
        continue
    if(co==0):
        print("Ashishgup")
        continue
    if(co>1):        
        print("Ashishgup")
        continue
    no=n//(2**co)
##    if(no==1):
##        if(co%2==1):
##            print("Ashishgup")
##        else:
##            print("FastestFinger")
##        continue
##    if(co%2==1):
##        print("Ashishgup")
##        continue
    j=2
    mi=1
    while j*j<=no:
        mi=min(mi,no%j)
        j+=1
    if(mi>0):
        print("FastestFinger")
        continue
    print("Ashishgup")