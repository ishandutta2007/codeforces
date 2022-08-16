n,k=map(int,input().split())
 
    
it=list(input())
it=[int(i) for i in it]
 
    #print(n)
ans=[0 for i in range(n)]
for i in range(k):
    for j in range(i,n,k):
        ans[j]=it[i]
    
if int(''.join([str(i) for i in ans]))>=int(''.join([str(i) for i in it])):
    print(n)    
    print(''.join([str(i) for i in ans]))
else:
    #ma=[it[i] for i in range(k)]
    ans=[it[i] for i in range(k)]
    stt=0
    for i in range(n):
        if it[i]>it[i%k]:
            ind=i
            #it[i%k]=it[i]
            break
    for i in range(k-1,-1,-1):
        if ans[i]==9:
            ans[i]=0
            continue
        ans[i]+=1
        ind2=i
        break
    ans2=[0 for i in range(n)]
    for i in range(k):
        for j in range(i,n,k):
            ans2[j]=ans[i]
    print(n)
    
    print(''.join([str(i) for i in ans2]))