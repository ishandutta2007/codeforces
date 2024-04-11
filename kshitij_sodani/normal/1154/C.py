a,b,c=map(int,input().split())
s={0:0,3:0,6:0,1:1,5:1,2:2,4:2}
oo=0
aa,bb,cc=a,b,c
if True:
    kk=(a+b+c)//7
    if min([a//3,b//2,c//2])==a//3:
        nn=a//3
        a=a%3
        b-=nn*2
        c-=nn*2
    elif min([a//3,b//2,c//2])==b//2:
        nn=b//2
        b=b%2
        a-=nn*3
        c-=nn*2
    elif min([a//3,b//2,c//2])==c//2:
        nn=c//2
        c=c%2
        a-=nn*3
        b-=nn*2
#print(a,b,c)
st=(aa+bb+cc)-(a+b+c)
for i in range(7):
    mm=[a,b,c]
    ind=i
    while True:
        ind+=1
        ind=ind%7
        if mm[s[ind]]==0:
            break
        else:
            mm[s[ind]]-=1
    oo=max(oo,(a+b+c)-sum(mm))
print(oo+st)