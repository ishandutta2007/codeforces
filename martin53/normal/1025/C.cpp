#include<bits/stdc++.h>
using namespace std;
char which(char x,int q)
{
    if(q%2==1)
    {
        if(x=='b')return 'w';
        return 'b';
    }
    return x;
}
int main()
{
string s;
cin>>s;
s=s+s;
int ans=0,SZ=s.size();
for(int i=0;i<SZ;i++)
{
    int j=i+1;
    while(j<SZ&&s[i]==which(s[j],j-i))j++;
    ans=max(ans,j-i);
    i=j-1;
}
if(ans>s.size()/2)ans=s.size()/2;
cout<<ans<<endl;
return 0;
}