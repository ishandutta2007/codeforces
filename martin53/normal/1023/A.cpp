#include<bits/stdc++.h>
using namespace std;
int n,m;
string s,t;
int main()
{
cin>>n>>m;
cin>>s>>t;
int pos=-1;
for(int i=0;i<n;i++)
    if(s[i]=='*')pos=i;
if(pos==-1)
{
    if(s==t)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
if(n-1>m)
{
    cout<<"NO"<<endl;
    return 0;
}
for(int j=0;j<pos;j++)
    if(s[j]!=t[j])
    {
    cout<<"NO"<<endl;
    return 0;
    }
for(int j=n-1;j>pos;j--)
    if(s[j]!=t[m-1-(n-1-j)])
    {
    cout<<"NO"<<endl;
    return 0;
    }
cout<<"YES"<<endl;
return 0;
}