#include<bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long LL;
const int maxn=100005;
struct node
{
    int d,to;
    LL cost;
    bool operator < (const struct node &p)const
    {return d<p.d;}
};
vector<node> jin,chu;
int n,m,k,cnt;
LL pre[maxn],suf[maxn],now[maxn],sum;

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    while(m--)
    {
        int d,x,y;LL co;
        scanf("%d%d%d%lld",&d,&x,&y,&co);
        if(x==0)chu.pb({d,y,co});else jin.pb({d,x,co});
    }
    sort(chu.begin(),chu.end());
    sort(jin.begin(),jin.end());
    cnt=0;
    LL cs=1ll*(LL)n*(LL)(1e9);
    sum=cs;
    for(int i=1;i<=n;i++)now[i]=1e9;
    for(int i=0;i<jin.size();i++)
    {
        node t=jin[i];
        if(now[t.to]==1e9)cnt++;
        if(now[t.to]>t.cost)
        {
            sum-=now[t.to];
            sum+=t.cost;
            now[t.to]=t.cost;
        }
        if(cnt<n)pre[i]=cs;else pre[i]=sum;
    }
    cnt=0;
    for(int i=1;i<=n;i++)now[i]=1e9;
    sum=cs;
    int chus=chu.size();
    for(int i=chus-1;i>=0;i--)
    {
        node t=chu[i];
        if(now[t.to]==1e9)cnt++;
        if(now[t.to]>t.cost)
        {
            sum-=now[t.to];
            sum+=t.cost;
            now[t.to]=t.cost;
        }
        if(cnt<n)suf[i]=cs;else suf[i]=sum;
    }
    LL ans=1e18;
    int l=0,r=0;
    while(l<(int)jin.size() && pre[l]>=cs)l++;
    while(l<(int)jin.size())
    {
        while(r<(int)chu.size() && jin[l].d+k>=chu[r].d)r++;
        if(r>=(int)chu.size())break;
        if(pre[l]<cs && suf[r]<cs)ans=min(ans,pre[l]+suf[r]);
        l++;
    }
    if(ans==1e18)printf("-1\n");else printf("%lld\n",ans);
    return 0;
}