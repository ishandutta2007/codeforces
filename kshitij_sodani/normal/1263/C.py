t=int(input())
for _ in range(t):
    n=int(input())
    aa=[]
    ind=1
    while True:
        aa.append(n//ind)
        if len(aa)>=2:
            if aa[-1]==aa[-2]:
                for i in range(aa[-1],-1,-1):
                    aa.append(i)
                break
        ind+=1
    print(len(set(aa)))
    print(*sorted(list(set(aa))))