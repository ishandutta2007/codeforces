n=int(input())
it=list(map(int,input().split()))
s={}
for i in range(len(it)):
    for j in range(i+1,len(it)):
        try:
            s[it[i]+it[j]]+=1
        except:
            s[it[i]+it[j]]=1
            
x=max(list(s.values()))
print(x)