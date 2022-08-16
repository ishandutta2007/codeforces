t=int(input())
for _ in range(t):
    n=int(input())
    a,b,c=map(int,input().split())
    s=input()
    tot=0
    aa=s.count("S")
    bb=s.count("R")
    cc=s.count("P")
    tot=0
    tot+=min(a,aa)
    tot+=min(b,bb)
    tot+=min(c,cc)
    x=n//2
    if n%2==1:
        x+=1
    if tot>=x:
        print("YES")
        ss=[i for i in s]
        j=0
        tt=["" for i in range(n)]
        co=0
        for i in ss:
            if not(a):
                break
            if i=="S":
                tt[j]="R"
                a-=1
            
            j+=1
        j=0
        for i in ss:
            if not(b):
                break
            if i=="R":
                tt[j]="P"
                b-=1
            j+=1
        j=0
        for i in ss:
            if not(c):
                break
            if i=="P":
                tt[j]="S"
                c-=1
            j+=1
        for i in range(n):

            if tt[i]=="":
                if a:
                    tt[i]="R"
                    a-=1
                elif b:
                    tt[i]="P"
                    b-=1
                elif c:
                    tt[i]="S"
                    c-=1
        print(''.join(tt))
                    
        
                
    else:
        print("NO")