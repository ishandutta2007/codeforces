n=int(input())
it=list(input())
tt=it[:]
ans=[]
for i in range(n-1):
    if it[i]=="W":
        it[i]="B"
        if it[i+1]=="B":
            it[i+1]="W"
        else:
            it[i+1]="B"
        ans.append(i+1)
if it[-1]=="B":
    print(len(ans))
    print(*ans)
else:
    it=tt[:]
    ans=[]
    for i in range(n-1):
        if it[i]=="B":
            it[i]="W"
            if it[i+1]=="B":
                it[i+1]="W"
            else:
                it[i+1]="B"
            ans.append(i+1)
    if it[-1]=="W":
        print(len(ans))
        print(*ans)
    else:
        print(-1)