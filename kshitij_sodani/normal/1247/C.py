n,p=map(int,input().split())

        
if p>=n:
    print(-1)
else:
    nn=n
    j=1
    st=False
    while True:
        nn-=p
        if j>=10**6:
            st=True
            break
        if bin(nn).count("1")<=j and nn>=j:
            ans=j
            break
        j+=1
    if st:
        print(-1)
    else:
        print(j)
   # print(ans)