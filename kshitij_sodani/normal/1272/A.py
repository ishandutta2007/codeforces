t=int(input())
for _ in range(t):
    a,b,c=map(int,input().split())
    a,b,c=sorted([a,b,c])
    ma=0
    ma+=max(0,b-a-1)
    ma=float("inf")
    for i in [0,-1,1]:
        for j in [0,-1,1]:
            for k in [0,-1,1]:
            
                aa=a+i
                cc=c+j
                bb=b+k
                ma=min(ma,abs(aa-cc)+abs(aa-bb)+(cc-bb))
    
    print(ma)