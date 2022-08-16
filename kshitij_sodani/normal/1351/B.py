t=int(input())
for _ in range(t):
    aa=list(map(int,input().split()))
    bb=list(map(int,input().split()))
    st=0
    for i in range(2):
        for j in range(2):
            c=set()
            c.add(aa[i]+bb[j])
            c.add(aa[1-i])
            
            c.add(bb[1-j])
  
            if(len(c)==1):
                st=1
    if st==1:
        print("Yes")
    else:
        print("No")