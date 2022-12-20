#include<bits/stdc++.h>
#define int long long
using namespace std;
const int nmax=1e6+42;
struct rect
{
    int x,y,a;
};
bool cmp(rect p,rect q)
{
    return p.x<q.x;
}
int n;
rect inp[nmax];
int dp[nmax];
pair<int/*x*/,int/*y*/> help[nmax];
int id=0;
double meet(pair<int/*x*/,int/*y*/> p,pair<int/*x*/,int/*y*/> q)
{
    return 1.0*(q.second-p.second)/(p.first-q.first);
}
int get_value(int i,int x)
{
    return help[i].first*x+help[i].second;
}
int ask_min(int x)
{
    if(id==0)return 0;
    if(id==1)return get_value(1,x);
    int ret=1e18;
    /*
    for(int i=1;i<=id;i++)
        ret=min(ret,get_value(i,x));
    return ret;
    */
    if(meet(help[id-1],help[id])>=x)return get_value(id,x);
    int ok=id-1,not_ok=0;
    while(ok-not_ok>1)
    {
        int av=(ok+not_ok)/2;
        if(meet(help[av],help[av+1])<x)ok=av;
        else not_ok=av;
    }
    return get_value(ok,x);
}
signed main()
{
scanf("%lld",&n);
for(int i=1;i<=n;i++)scanf("%lld%lld%lld",&inp[i].x,&inp[i].y,&inp[i].a);
sort(inp+1,inp+n+1,cmp);

long long mx=0;
for(int i=n;i>=1;i--)
{
    dp[i]=inp[i].x*inp[i].y-inp[i].a-min(0LL,ask_min(inp[i].x));
    mx=max(mx,dp[i]);
    pair<int/*x*/,int/*y*/> now={inp[i].y,-dp[i]};
    while(id>=2&&meet(help[id-1],now)<=meet(help[id],now))id--;
    help[++id]=now;
    /*
    cout<<i<<" -> "<<dp[i]<<endl;
    for(int j=1;j<=id;j++)cout<<help[j].first<<" "<<help[j].second<<endl;
    */
}
printf("%lld\n",mx);
return 0;
}