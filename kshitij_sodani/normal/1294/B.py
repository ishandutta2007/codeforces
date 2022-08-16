import sys
input=sys.stdin.readline
t=int(input())
for _ in range(t):
    n=int(input())
    it=[list(map(int,input().split())) for i in range(n)]
    st=1
    for i in range(n):
        for j in range(n):
            if it[i][0]<it[j][0] and it[i][1]>it[j][1]:
                st=0
    if st==0:
        print("NO")
    else:
        it.sort()
        x=0
        y=0
        
        
        print("YES")
        for i in range(n):
            if it[i][0]==x:
                print("U"*(it[i][1]-y),end="")
                y=it[i][1]
            elif it[i][1]==y:
                print("R"*(it[i][0]-x),end="")
                x=it[i][0]
            else:
                
                print("R"*(it[i][0]-x),end="")
                print("U"*(it[i][1]-y),end="")
                x,y=it[i]
        print()