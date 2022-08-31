n=int(input())
it=list(map(int,input().split()))
kk=set(it)
if len(kk)>3:
    print(-1)
if len(kk)==1:
    print(0)
if len(kk)==2:
    kk=list(kk)
    kk.sort()
    if (kk[0]-kk[1])%2==0:
        print((kk[1]-kk[0])//2)
    else:
        print(kk[1]-kk[0])
if len(kk)==3:
    kk=list(kk)
    kk.sort()
    if kk[0]-kk[1]==kk[1]-kk[2]:
        print(kk[1]-kk[0])
    else:
        print(-1)