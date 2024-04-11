##import sys
##input=sys.stdin.readline
t=int(input())
for _ in range(t):
    n=int(input())
    it=[]
    
    oo=0
    zz=0
    oz=0
    zo=0
    tt=[]
    for i in range(n):
        it.append(input())
        if it[-1][0]=="0" and it[-1][-1]=="0":
            zz+=1
            
        elif it[-1][0]=="1" and it[-1][-1]=="1":
            oo+=1
        elif it[-1][0]=="0" and it[-1][-1]=="1":
            zo+=1
            tt.append((it[-1],i))
        else:
            oz+=1
            tt.append((it[-1],i))
    if oo and zz and oz==0 and zo==0:
        print(-1)
        continue
    if oo and zz==0 and oz==0 and zo==0:
        print(0)
        continue
    
    if oo==0 and zz and oz==0 and zo==0:
        print(0)
        continue
    if zo==oz:
        print(0)
        continue
    oo=0
    zz=0
    
    ss=set()
    sss=set()
    so=set()
    soo=set()
    
    for i in tt:
        if i[0][0]=="0" and i[0][-1]=="1":
            ss.add(i)
            sss.add(i[0])
        else:
            so.add(i)
            soo.add(i[0])
    tot=0
    if oz<zo:
        ans=[]
        
        while oz<zo-1 and ss:
            s=ss.pop()
            if s[0][-1::-1] in soo:
                continue
            oz+=1
            zo-=1
            ans.append(s[1]+1)
            tot+=1
        if oz<zo-1:
            print(-1)
        else:
            print(tot)
            ans.sort()
            
            print(*ans)
    else:
        ans=[]
        while zo<oz-1 and so:
            s=so.pop()
            if s[0][-1::-1] in sss:
                continue
            zo+=1
            
            oz-=1
            tot+=1
            ans.append(s[1]+1)
        if zo<oz-1:
            print(-1)
        else:
            print(tot)
            ans.sort()
            print(*ans)