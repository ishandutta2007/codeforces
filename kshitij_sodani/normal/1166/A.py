n=int(input())
s={}
for i in range(n):
    ss=input()
    try:
        s[ss[0]]+=1
    except:
        s[ss[0]]=1
k=[0,0]
for i in s:
    a=s[i]//2
    b=s[i]-a
    k[0]+=(a*(a-1))//2
    k[1]+=(b*(b-1))//2
print(sum(k))