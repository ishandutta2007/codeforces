s=raw_input();
n=len(s);
a=[-1];
ans=0;
for i in range(1,n+1,2):
    if i==n or s[i]=='*':
        for j in a:
            'print s[:j+1]+"("+s[j+1:i]+")"+s[i:];'
            ans=max(ans,eval(s[:j+1]+"("+s[j+1:i]+")"+s[i:]));
        a.append(i);
print ans;