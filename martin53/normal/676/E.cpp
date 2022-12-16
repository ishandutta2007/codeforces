#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n,k;
string inp[nmax];
long long take(string s)
{
    int mult=1;
    long long ret=0;
    for(auto k:s)
        if(k=='-')mult=-1;
        else ret=ret*10+(k-'0');
    return ret*mult;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cin>>n>>k;
for(int i=0;i<=n;i++)cin>>inp[i];
if(k==0)
{
    if(inp[0]=="?")
    {
        int pl=0;
        for(int i=1;i<=n;i++)
            if(inp[i]!="?")pl=!pl;
        if(pl%2==0)cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
        return 0;
    }
    else
    {
        if(inp[0]=="0")cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        return 0;
    }
}
bool q=0;
for(int i=0;i<=n;i++)
    if(inp[i]=="?")q=1;
if(q)
{
        if(n%2==0)cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
        return 0;
}
    long long val=0;
    for(int i=0;i<=n;i++)
    {
        long long now=take(inp[i]);
        if(val%k!=0)
        {
            cout<<"No"<<endl;
            return 0;
        }
        val=val/k+now;
    }
if(val==0)cout<<"Yes"<<endl;
else cout<<"No"<<endl;
return 0;
}