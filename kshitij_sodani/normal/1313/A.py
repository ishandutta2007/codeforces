#list(map(int,input().split()))
t=int(input())
def brute(ind,su=[0,0,0],co=0):
    global ma
    if ind==7:
        if su[0]<=a and su[1]<=b and su[2]<=c:
            ma=max(ma,co)
        return
    brute(ind+1,[su[i]+aa[ind][i] for i in range(3)],co+1)
    brute(ind+1,su,co)
for i in range(t):
    a,b,c=list(map(int,input().split()))
    ma=0
    aa=[[1,1,1],[1,1,0],[1,0,0],[1,0,1],[0,1,1],[0,1,0],[0,0,1]]
    brute(0)
    print(ma)