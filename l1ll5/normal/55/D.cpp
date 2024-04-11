#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mod 2520
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int T;
ll dp[20][mod][50];//dig mod lcm
int mp[mod+5];
int a[20],tot;
void init()
{
    int cnt=0;
    for(int i=1;i<=mod;i++)
    if(mod%i==0)mp[i]=cnt++;
}
ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
ll dfs(int dig,int rem,int lcm,bool f)
{
    if(!dig)return rem%lcm==0;
    if(!f&&~dp[dig][rem][mp[lcm]])return dp[dig][rem][mp[lcm]];
    ll ret=0;
    int end=f?a[dig]:9;
    for(int i=0;i<=end;i++)ret+=dfs(dig-1,(rem*10+i)%mod,i?lcm*i/gcd(i,lcm):lcm,f&&i==end);
    if(!f)dp[dig][rem][mp[lcm]]=ret;
    return ret;
}
ll solve(ll x)
{
    tot=0;
    while(x)a[++tot]=x%10,x/=10;
    return dfs(tot,0,1,1);
}
int main()
{
    T=read();
    init();
    memset(dp,-1,sizeof(dp));
    while(T--)
    {
        ll l,r;
        cin>>l>>r;
        cout<<solve(r)-solve(l-1)<<endl;
    }
}