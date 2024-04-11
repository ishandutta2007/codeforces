#include <bits/stdc++.h>
#define MAXN 200007
#define MOD 998244353
using namespace std;
vector<int> g[MAXN];
set<pair<int,int>> st[MAXN];
int a[MAXN];
long long cnt[MAXN],sol[MAXN],full;
long long c3(long long k) {return ((k*(k-1)*(k-2))/6)%MOD;}
long long total(long long k, long  long t) {return (c3(k)-c3(t)-c3(k-t)+3LL*MOD)%MOD;}
void dfs(int s,int f)
{
    for(int i=0;i<g[s].size();i++) if(g[s][i]!=f) dfs(g[s][i],s);
    for(auto it : st[s]) sol[s]=(sol[s]+total(cnt[it.first],it.second))%MOD;
    for(int i=0;i<g[s].size();i++) if(g[s][i]!=f && st[g[s][i]].size()>st[s].size()) {swap(st[g[s][i]],st[s]); sol[s]=sol[g[s][i]];}
    for(int i=0;i<g[s].size();i++) if(g[s][i]!=f)
    {
        for(auto it : st[g[s][i]])
        {
            int x=it.first,y=it.second;
            pair<int,int> pi=*st[s].lower_bound({x,0});
            if(st[s].lower_bound({x,0})!=st[s].end() && pi.first==x)
            {
                st[s].erase(pi);
                sol[s]=(sol[s]-total(cnt[x],pi.second)+total(cnt[x],pi.second+y)+MOD)%MOD;
                st[s].insert({x,pi.second+y});
            }
            else
            {
                sol[s]=(sol[s]+total(cnt[x],y))%MOD;
                st[s].insert({x,y});
            }
        }
        st[g[s][i]].clear();
    }
    full=(full+sol[s])%MOD;
}
int main()
{
    int n,cur=1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) for(int j=2;j<=500;j++) if(a[i]%j==0)
    {
        cnt[j]++;
        st[i].insert({j,1});
        while(a[i]%j==0) a[i]/=j;
    }
    for(int i=1;i<=n;i++) if(a[i]>1) {cnt[a[i]]++; st[i].insert({a[i],1});}
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,1);
    printf("%lld",full);
}