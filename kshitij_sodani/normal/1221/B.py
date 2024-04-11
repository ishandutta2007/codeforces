n=int(input())
ans=[[0]*n for i in range(n)]
for i in range(n):
    for j in range(n):
        if(i+j)%2==0:
            ans[i][j]="B"
        else:
            ans[i][j]="W"
for i in ans:
    print(''.join(i))