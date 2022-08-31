a=[map(int,raw_input().split()) for i in range(3)]
for x in range(100000):
    b=[[a[i][j] for j in range(3)] for i in range(3)]
    b[0][0]=x+1
    s=sum(b[0])
    p=0
    for i in range(1,3):
        b[i][i]=s-sum(b[i])
        if b[i][i]<=0 or b[i][i]>100000:
            p=1
    if p==1:
        continue
    if sum(sum(b[k][i] for i in range(3))==s for k in range(3))==3:
        if sum(b[i][i] for i in range(3))==s:
            if sum(b[i][2-i] for i in range(3))==s:
                for i in range(3):
                    for j in range(3):
                        print b[i][j],
                    print
                exit()