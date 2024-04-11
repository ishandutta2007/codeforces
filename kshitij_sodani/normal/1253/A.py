t=int(input())
for _ in range(t):
    n=int(input())
    aa=list(map(int,input().split()))
    bb=list(map(int,input().split()))
    st=False
    diff=0
    ans="YES"
    for i in range(n):
        if st:
            if aa[i]-bb[i]!=diff:
                if aa[i]-bb[i]!=0:
                    ans="NO"
                else:
                    diff=0
            continue
        if aa[i]!=bb[i]:
            st=True
            diff=aa[i]-bb[i]
            if diff>0:
                ans="NO"
        
    print(ans)