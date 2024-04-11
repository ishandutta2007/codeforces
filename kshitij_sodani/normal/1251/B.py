t=int(input())
for _ in range(t):
    n=int(input())
    it=[]
    co=0
    coo=0
    for i in range(n):
        a=input()
        co+=a.count("1")
        coo+=a.count("0")
        it.append([a.count("1"),a.count("0")])
    it.sort(key=lambda x:x[0]+x[1])
    ans=0
    for i in range(n):
        m=it[i][0]+it[i][1]
        if co==0 and coo==0:
            break
        if m%2==1:
            if co%2==1:
                co-=1
            elif coo%2==1:
                coo-=1
            m-=1
            st=True
            while m>0:
                if co>1:
                    co-=2
                    m-=2
                    continue
                if coo>1:
                    coo-=2
                    m-=2
                    continue
                st=False
                break
            if st:
                ans+=1
                continue
            else:
                break
        else:
            st=True
            while m>0:
                if co>1:
                    co-=2
                    m-=2
                    continue
                if coo>1:
                    coo-=2
                    m-=2
                    continue
                st=False
                break
            if st:
                ans+=1
                continue
            else:
                break
    print(ans)