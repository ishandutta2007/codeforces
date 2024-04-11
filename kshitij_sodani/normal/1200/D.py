n,k=map(int,input().split())
it=[[0]*n for i in range(n)]
t=[[-1,-1] for i in range(n)]
tt=[[-1,-1] for i in range(n)]
for i in range(n):
    s=input()
    c=-1
    cc=-1
    for j,ii in enumerate(s):
        if ii=="B":
            it[i][j]=1
            if c==-1:
                c=j
            cc=j
    t[i]=[c,cc]

for i in range(n):
    p=[it[j][i] for j in range(n)]
    c=-1
    cc=-1
    for j in range(n):
        if p[j]:
            if c==-1:
                c=j
            cc=j
    tt[i]=[c,cc]
row_max=[[0]*(n-k+1) for i in range(n-k+1)]
col_max=[[0]*(n-k+1) for i in range(n-k+1)]
for col in range(n-k+1):
    s=[0]*n
    co=0
    for i in range(k):
        if t[i]!=[-1,-1]:
            if t[i][0]>=col and t[i][0]<=col+k-1 and t[i][1]>=col and t[i][1]<=col+k-1:
                co+=1
                s[i]=1
    row_max[col][0]=co
    for row in range(1,n-k+1):
        if s[row-1]:
            co-=1
        i=row+k-1
        if t[i]!=[-1,-1]:
            if t[i][0]>=col and t[i][0]<=col+k-1 and t[i][1]>=col and t[i][1]<=col+k-1:
                co+=1
                s[i]=1
        row_max[col][row]=co
for row in range(n-k+1):
    s=[0]*n
    co=0
    for i in range(k):
        if tt[i]!=[-1,-1]:
            if tt[i][0]>=row and tt[i][0]<=row+k-1 and tt[i][1]>=row and tt[i][1]<=row+k-1:
                co+=1
                s[i]=1
    col_max[0][row]=co
    for col in range(1,n-k+1):
        if s[col-1]:
            co-=1
        i=col+k-1
        if tt[i]!=[-1,-1]:
            if tt[i][0]>=row and tt[i][0]<=row+k-1 and tt[i][1]>=row and tt[i][1]<=row+k-1:
                co+=1
                s[i]=1
        col_max[col][row]=co
ma=0
for i in range(n-k+1):
    for j in range(n-k+1):
        ma=max(ma,row_max[i][j]+col_max[i][j])
ma+=t.count([-1,-1])
ma+=tt.count([-1,-1])
print(ma)