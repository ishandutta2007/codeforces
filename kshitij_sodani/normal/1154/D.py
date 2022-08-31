n,b,a=map(int,input().split())
it=list(map(int,input().split()))
aa=a

st=False
for i in range(len(it)):
    if b==0 and a==0:
        st=True
        break
    if it[i]==0 or a==aa:
        if a>0:
            a-=1
        elif b>0:
            b-=1
        else:
            st=True
            break
        continue
    else:
        if b>0:
            b-=1
            if a<aa:
                a+=1
            continue
        elif a>0:
            a-=1
            continue
        else:
            st=True
            break
    
if st:
    print(i)
else:
    print(n)