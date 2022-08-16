n,s,t=map(int,raw_input().split())
p=[0]+map(int,raw_input().split())
u=[0]*(n+1)
x=0
while s!=t:
    if u[s]:
        print -1
        exit()
    u[s]=1
    x+=1
    s=p[s]
print x