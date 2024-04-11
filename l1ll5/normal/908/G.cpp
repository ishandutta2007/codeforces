#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 705
#define ll long long
#define mod 1000000007
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
typedef pair<int,int> pr;
pr dp[N];
#define fi first
#define se second
int n,a[N];
char s[N];
void add(int &x,int y){(x+=y)>=mod?x-=mod:x;}
pr dfs(int dig,int d,bool flag)
{
    if(!dig)return make_pair(0,1);
    if(dp[dig].fi!=-1&&!flag)return dp[dig];
    int end=flag?a[dig]:9;
    pr tmp;
    tmp.fi=0,tmp.se=0;
    for(int i=0;i<=end;i++)
    {
        pr ret=dfs(dig-1,d,flag&&i==a[dig]);
        add(tmp.se,ret.se);
        if(i<d)add(tmp.fi,ret.fi);
        else add(tmp.fi,(1ll*10*ret.fi+ret.se)%mod);
    }
    dp[dig]=tmp;
    return tmp;
}
int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    reverse(s+1,s+n+1);
    for(int i=1;i<=n;i++)a[i]=s[i]-'0';
    int ans=0;
    for(int i=1;i<=9;i++)
    {
        memset(dp,-1,sizeof(dp));
        add(ans,dfs(n,i,1).fi);
    }
    cout<<ans<<endl;
}