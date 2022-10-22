#include<bits/stdc++.h>
using namespace std;
int n,m,k,q;
vector<pair<int,int> > a[500000];
pair<int,long long> d[500000];
vector<pair<long long,pair<int,int> > > e;
priority_queue<pair<long long,int> > pq;
bool ob[500000];
void dijkstra() {
    for(int i=1;i<=n;i++) d[i]={-1,1e18};
    for(int i=1;i<=k;i++) {
        d[i]={i,0};
        pq.push({0,i});
    }
    while(pq.size()>0) {
        int u=pq.top().second;
        pq.pop();
        if(!ob[u]) {
            ob[u]=true;
            int v,w;
            for(int i=0;i<a[u].size();i++) {
                v=a[u][i].first;
                w=a[u][i].second;
                if(d[v].second>d[u].second+w) {
                    d[v]={d[u].first,d[u].second+w};
                    pq.push({-(d[u].second+w),v});
                }
            }
        }
    }
}
int comp[500000];
vector<int> cp[500000];
long long ans[500000];
vector<pair<int,int> > que[500000];
int main() {
    scanf("%d %d %d %d",&n,&m,&k,&q);
    int u,v;
    long long w;
    for(int i=1;i<=m;i++) {
        scanf("%d %d %lld",&u,&v,&w);
        a[u].push_back({v,w});
        a[v].push_back({u,w});
    }
    for(int i=1;i<=q;i++) {
        scanf("%d %d",&u,&v);
        que[u].push_back({i,v});
        que[v].push_back({i,u});
        ans[i]=1e18;
    }
    dijkstra();
    for(int i=1;i<=n;i++) {
        u=i;
        for(int j=0;j<a[u].size();j++) {
            v=a[u][j].first;
            w=a[u][j].second;
            if(d[u].first!=d[v].first) e.push_back({w+d[u].second+d[v].second,{d[u].first,d[v].first}});
        }
    }
    sort(e.begin(),e.end());
    for(int i=1;i<=k;i++) {
        cp[i].push_back(i);
        comp[i]=i;
    }
    for(auto t:e) {
        u=t.second.first;
        v=t.second.second;
        w=t.first;
        if(comp[u]!=comp[v]) {
            u=comp[u];
            v=comp[v];
            if(cp[u].size()>cp[v].size()) {
                for(int i=0;i<cp[v].size();i++) {
                    comp[cp[v][i]]=u;
                    for(auto qt:que[cp[v][i]]) {
                        if(comp[cp[v][i]]==comp[qt.second]) {
                            ans[qt.first]=min(ans[qt.first],w);
                        }
                    }
                    cp[u].push_back(cp[v][i]);
                }
                cp[v].clear();
            }
            else {
                for(int i=0;i<cp[u].size();i++) {
                    comp[cp[u][i]]=v;
                    for(auto qt:que[cp[u][i]]) {
                        if(comp[cp[u][i]]==comp[qt.second]) {
                            ans[qt.first]=min(ans[qt.first],w);
                        }
                    }
                    cp[v].push_back(cp[u][i]);
                }
                cp[u].clear();
            }
        }
    }
    for(int i=1;i<=q;i++) printf("%lld\n",ans[i]);
    return 0;
}