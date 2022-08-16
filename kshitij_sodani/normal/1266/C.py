r,c=map(int,input().split())

if r==1 and c==1:
    print(0)
else:
    if r<=c:
        gr=[[0 for i in range(c)] for j in range(r)]
        for i in range(c):
            gr[0][i]=r+i+1
        for i in range(1,r):
            for j in range(c):
                gr[i][j]=gr[0][j]*(i+1)
          #      mi=max(mi,gr[i][j])
    else:
        
        gr=[[0 for i in range(c)] for j in range(r)]
        for i in range(r):
            gr[i][0]=c+i+1
        for i in range(1,c):
            for j in range(r):
                gr[j][i]=gr[j][0]*(i+1)
             #   ma=max(ma,gr[j][i])
        
    
    for i in range(r):
        print(*gr[i])