ouf = open("test.out", mode="w")

def printf(sth):
    print(sth, file=ouf)

q=int(input())
while q>0:
    q=q-1
    n=int(input())
    bsc=[]
    for i in range(40, -1, -1):
        bsc.append(0)
        while n>=3**i:
            bsc[40-i]+=1
            n-=(3**i)
    ptr=0
    # print(bsc)
    while ptr<41:
        if bsc[ptr]==2:
            break
        ptr+=1
    if ptr<41:
        for i in range(ptr, 41):
            bsc[i]=0
        ptr=ptr-1
        while ptr>0:
            if bsc[ptr]==0:
                break
            bsc[ptr]=0
            ptr-=1
        bsc[ptr]=bsc[ptr]+1
    ans=0
    #print(bsc)
    for i in range(41):
        if bsc[40-i]==1:
            ans+=(3**i)
    print(ans)