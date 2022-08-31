t=int(input())
for _ in range(t):
    s=input()
    ind=[]
    n=len(s)
    tot=0
    ans=set()
    for i in range(n-2):
        if s[i:i+3]=="one":
            tot+=1
            ans.add(i+1)
        if s[i:i+3]=="two":
            tot+=1
            ans.add(i+1)
        
    for i in range(n-4):
        if s[i:i+5]=="twone":
            tot-=1
            ans.remove(i+1)
            ans.remove(i+3)
            ans.add(i+2)
    print(tot)
    for i in ans:
        print(i+1,end=" ")
    print()
    continue
    tt=[]
    oo=[]
    for i in range(0,n):
        if s[i]=="t":
            try:
                tt.append(tt[-1]+1)
            except:
                tt.append(1)
        else:
            tt.append(0)
        if s[i]=="o":
            try:
                oo.append(tt[-1]+1)
            except:
                oo.append(1)
        else:
            oo.append(0)
    oo2=[0]*n
    ee=[0]*n
    for i in range(n-1,-1,-1):
        
        if s[i]=="o":
            try:
                oo2[i]=1+oo[i+1]
            except:
                oo2[i]=1
        else:
            oo2[i]=0
        if s[i]=="e":
            try:
                ee[i]=1+ee[i+1]
            except:
                ee[i]=1
        else:
            ee[i]=0
    tot=0
    for i in range(n-2):
        if s[i:i+3]=="one":
            tot+=min(oo[i],ee[i+2])
        elif s[i:i+3]=="two":
            tot+=min(tt[i],oo2[i+2])
    st=0
    for i in range(n):
        if i<n-1:
            if s[i:i+2]=="tw":
                st=1
                ind=i
        if st and s[i]=="o":
            st+=1
        if st and s[i]!="o":
            
            if i<n-1:
                if s[i:i+2]=="ne" and st>1:
                    ans=0
                    ans+=min(tt[ind],oo2[ind+2])
                    ans+=min(ee[i+1],oo[i-1])
                    if st-1<ans:
                        tot-=ans
                        tot+=st-1
            st=0
    print(tot)