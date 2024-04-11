n,k=map(int,input().split())
s=list(input())
ss=set(list(input()))
co=0
tot=0
for i in range(n):
    if s[i] not in ss:
        co+=((tot*(tot+1))//2)
        tot=0
        
        continue
    else:
        tot+=1
co+=((tot*(tot+1))//2)
print(co)