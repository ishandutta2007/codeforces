#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 2005
#define mod 1000000007
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,d;
char s[N];
int a[N];
int ans;
int dp[N][N];
int add(int a,int b){return (a+=b)>=mod?a-mod:a;}
int dfs(int dig,int num,bool flag)
{
    if(dig==n+1)return num==0;
    if(!flag&&~dp[dig][num])return dp[dig][num];
    int end=flag?a[dig]:9;
    int ret=0;
    for(int i=0;i<=end;i++)
    {
        if(dig%2==0&&i==d)ret=add(ret,dfs(dig+1,(num*10+i)%m,flag&&i==end));
        if(dig%2==1&&i!=d)ret=add(ret,dfs(dig+1,(num*10+i)%m,flag&&i==end));
    }
    if(!flag)dp[dig][num]=ret;
    return ret;
}
int solve()
{
    scanf("%s",s+1);
    memset(dp,-1,sizeof(dp));
    n=strlen(s+1);
    for(int i=1;i<=n;i++)a[i]=s[i]-'0';
    int ret=dfs(1,0,1);
    return ret;
}
bool ck()
{
    int ret=0;
    for(int i=1;i<=n;i++)
    {
        if(i%2==1&&a[i]==d)return 0;
        if(i%2==0&&a[i]!=d)return 0;
        ret*=10;
        ret+=a[i];
        ret%=m;
    }
    return !ret;
}
int main()
{
    m=read(),d=read();
    int l=solve();
    l-=ck();
    int r=solve();
    ans=r-l;
    ans%=mod,ans+=mod,ans%=mod;
    cout<<ans<<endl;
}