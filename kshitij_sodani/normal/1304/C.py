q=int(input())
for _ in range(q):
    n,m=map(int,input().split())
    it=[list(map(int,input().split())) for i in range(n)]
    l=m
    r=m

    prev=0
    st=0
    it.sort()
    for i in range(n):
        l-=it[i][0]-prev
        r+=it[i][0]-prev
        
        if r<it[i][1]:
            st=1
            break
        elif l>it[i][2]:
            st=1
            break
        l=max(l,it[i][1])
        r=min(r,it[i][2])
      #  print(l,r)
        prev=it[i][0]
    if st:
        print("NO")
    else:
        print("YES")