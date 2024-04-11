t=int(input())
for _ in range(t):
    s=input()
    n=len(s)
    ans=""
    l=""
    ind=0
    while ind<n:
        if ind<n-1:
            if s[ind]==s[ind+1]:
                ind+=2
                continue
            else:
                ans+=s[ind]
                ind+=1
        if ind==n-1:
            ans+=s[ind]
            ind+=1
            
    ans=list(set(list(ans)))
    ans.sort()
    print(''.join(ans))