s=list(input())
s=[ord(i)-97 for i in s]
co=[[0 for i in range(26)] for j in range(26)]
pre=[0 for i in range(26)]
pre[s[0]]=1
for i in range(1,len(s)):
    for j in range(26):
        co[s[i]][j]+=pre[j]
    pre[s[i]]+=1
print(max(max([max(i) for i in co]),max(pre)))