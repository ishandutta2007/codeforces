for _ in range(int(input())):
    a,b,c=map(int,input().split())
    tot=min(a,b)
    if(a+b+c)<tot*3:
        re=a-tot+b-tot+c
        tot=(a+b+c)//3
    print(tot)