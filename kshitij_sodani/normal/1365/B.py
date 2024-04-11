t=int(input())
for _  in range(t):
    n=int(input())
    aa=list(map(int,input().split()))
    bb=list(map(int,input().split()))
    st=0
    ac=[aa[i] for i in range(n) if bb[i]==0]
    bc=[aa[i] for i in range(n) if bb[i]==1]
    if(len(ac)==0 or len(bc)==0):
        if(len(ac)==0):
            if(bc!=sorted(bc)):
                print("No")
            else:
                print("Yes")
        else:
            if(sorted(ac)!=ac):
                print("No")
            else:
                print("Yes")
            
    else:
        print("Yes")