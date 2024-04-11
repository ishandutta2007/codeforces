n=int(input())
it=list(input())
it=[ord(i)-97 for i in it]
lds=[1]
pre=[0 for i in range(26)]
pre[it[0]]=1
for i in range(1,n):
    lds.append(1)
    pre[it[i]]=max(pre[it[i]],1)
    for j in range(it[i]+1,26):
        pre[it[i]]=max(pre[it[i]],pre[j]+1)
    lds[-1]=pre[it[i]]
print(max(lds))
print(*lds)