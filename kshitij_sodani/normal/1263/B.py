t=int(input())
for _ in range(t):
    n=int(input())
    vis=set()
    it=[input() for i in range(n)]
    ss={}
    ans=[]
    j=0
    for i in it:
        try:
        
            ss[i].append(j)
        except:
            ss[i]=[j]
        j+=1
    tot=0
    x=list(ss.keys())[:]
    for i in x:
        if len(ss[i])==1:
            continue
        for kk in ss[i][1:]:
            for jj in range(10):

                j=i
                j=j[:3]+str(jj)
                try:
                    x=ss[j]
                except:
                    tot+=1
                    ss[j]=[kk]
                    break
        ss[i]=[ss[i][0]]
    for i in ss:
        ans.append([i,ss[i][0]])
    
    ans.sort(key=lambda x:x[1])
    print(tot)
    for i in ans:
        print(i[0])