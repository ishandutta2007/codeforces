n=int(input())
for i in range(n):
    s=list(input())
    s=[int(i) for i in s]
    try:
        s.remove(0)
        x=sum(s)
        if x%3==0:
            if len([i for i in s if i%2==0])>0:
                print("red")
            else:
                print("cyan")
        else:
            print("cyan")
    except:
        print("cyan")