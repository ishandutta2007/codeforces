#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

vector<int> g[505050];
set<int> g2[505050];

int u[505050];
int us[505050];
set<pair<int, pair<int, int> > > es[505050];

int getu(int x){
    if (u[x]==x) return x;
    return u[x]=getu(u[x]);
}

void un(int a, int b){
    a=getu(a);
    b=getu(b);
    if (a==b) return;
    if (us[a]>us[b]) swap(a, b);
    u[a]=b;
    us[b]+=us[a];
    for (auto ee:es[a]){
        es[b].insert(ee);
    }
    es[a].clear();
}

vector<pair<int, pair<int, int> > > g3[505050];

int o[505050];
vector<pair<int, pair<int, int> > > od;

pair<int, int> pe[505050];

void dfs2(int x, int p){
    for (auto nx:g3[x]){
        if (nx.F!=p){
            pe[nx.F]=nx.S;
            dfs2(nx.F, x);
        }
    }
    if (p>0){
        od.push_back({x, pe[x]});
        o[x]=od.size();
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        g2[a].insert(b);
        g2[b].insert(a);
    }
    for (int i=1;i<=n;i++){
        u[i]=i;
        us[i]=1;
    }
    for (int i=1;i<=n;i++){
        for (int nx:g[i]){
            if (g2[i].count(nx)){
                un(i, nx);
            }
        }
    }
    for (int i=1;i<=n;i++){
        for (int nx:g[i]){
            if (getu(nx)!=getu(i)){
                g3[getu(i)].push_back({getu(nx), {nx, i}});
            }
        }
    }
    for (int i=1;i<=n;i++){
        if ((int)g3[i].size()>0){
            dfs2(i, 0);
            break;
        }
    }
    for (int i=1;i<=n;i++){
        for (int nx:g2[i]){
            if (getu(nx)!=getu(i)){
                es[getu(nx)].insert({o[getu(i)], {nx, i}});
            }
        }
    }
    set<pair<int, int> > ud;
    vector<pair<pair<int, int>, pair<int, int> > > v;
    for (auto x:od){
        //cout<<x<<" x "<<pa[x]<<endl;
        x.F=getu(x.F);
        while (1){
            auto t=*es[x.F].rbegin();
            if (ud.count({min(t.S.F, t.S.S), max(t.S.F, t.S.S)})==1) {
                es[x.F].erase(t);
            }
            else{
                //cout<<t.S.F<<" "<<t.S.S<<endl;
                v.push_back({x.S, {t.S.F, t.S.S}});
                ud.insert({min(t.S.F, t.S.S), max(t.S.F, t.S.S)});

                un(t.S.F, t.S.S);
                break;
            }
        }
    }
    cout<<v.size()<<'\n';
    for (auto vv:v){
        cout<<vv.F.F<<" "<<vv.F.S<<" "<<vv.S.F<<" "<<vv.S.S<<'\n';
    }
}