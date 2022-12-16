#include<bits/stdc++.h>
using namespace std;
const int nmax=2e3+42,inf=1e9;
string s,p;
int n;
int where[nmax];
int dp[nmax][nmax];//min cost to achieve j substrings if we are on position i
int outp[nmax];
int rec(int pos,int rem)
{
    if(rem==0)return 0;
    if(pos==n)return inf;
    if(dp[pos][rem]!=-1)return dp[pos][rem];
    int ans=rec(pos+1,rem);//ignore
    if(where[pos]!=-1)
    {
    int v=rec(where[pos],rem-1)+where[pos]-pos-p.size();
    ans=min(ans,v);
    }
    dp[pos][rem]=ans;
    return ans;
}
int main()
{
cin>>s>>p;
n=s.size();
for(int i=0;i<n;i++)
{
    int now=0;
    int j=i;
    while(now<p.size()&&j<n)
    {
        if(p[now]==s[j])now++;
        j++;
    }
    if(now==p.size())where[i]=j;
    else where[i]=-1;
}
memset(dp,-1,sizeof(dp));
int pos=0,t=0;
while(pos<n)
{
    if(where[pos]!=-1)pos=where[pos],t++;
    else break;
}
for(int c=1;c<=t;c++)
{
    for(int j=rec(0,c);j<=n-c*p.size();j++)
        outp[j]=max(outp[j],c);
}
for(int i=0;i<=n;i++)cout<<outp[i]<<" ";cout<<endl;
return 0;
}