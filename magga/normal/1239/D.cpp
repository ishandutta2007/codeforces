#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define rep(i,n) for(int i = 0;  i < n ; ++i)
#define REP(i,a,b) for(int i = a ; i <= b ; ++i)
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<" :";
#define s(n) scanf("%d",&n)
#define rev(i,n) for(int i = n ; i >= 0 ; --i)
#define REV(i,a,b) for(int i = a ; i >= b ; --i)
#define miN(a,b) (((a)<(b))?(a):(b))
#define sc(n) scanf("%c",&n)
#define tr(c,i) for(typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define INF 1000000000
#define pii pair<long long int,long long int>
#define pb(a) push_back(a)
#define F first
#define S second
typedef long long ll;
using namespace std;
ll n,m,u,v;
vector < vector<int> > g(1000001), gr(1000001);
vector<bool> used,vis;
vector<int> order, component;
void dfs1 (int v) {
    used[v] = true;
    for (size_t i=0; i<g[v].size(); ++i)
        if (!used[ g[v][i] ])
            dfs1 (g[v][i]);
    order.push_back (v);
}
void dfs2 (int v) {
    used[v] = true;
    component.push_back (v);
    for (size_t i=0; i<gr[v].size(); ++i)
        if (!used[ gr[v][i] ])
            dfs2 (gr[v][i]);
}
set<int>ans;
void dfs3(int i){
    if(vis[i]){
        return;
    }
    vis[i]=1;
    ans.insert(i);
    for(auto i:g[i]){
        dfs3(i);
    }
}
void pre(){}
void solve(){
    cin>>n>>m;
    for(int i=0;i<n;i++)
        g[i].clear(),gr[i].clear();
    for(int i=0;i<m;i++){
        cin>>u>>v;
        u--;v--;
        g[u].push_back(v);
        gr[v].push_back(u);
    }
    used.assign (n, false);
    for (int i=0; i<n; ++i)
        if (!used[i])
            dfs1 (i);
    used.assign (n, false);
    for (int i=0; i<n; ++i) {
        int v = order[n-1-i];
        if (!used[v]) {
            dfs2 (v);
            if(component.size()==n){
                cout<<"No"<<"\n";
                return;
            }
            vis.assign (n, false);
            dfs3(component[0]);
            if(ans.size()!=n){
                cout<<"Yes"<<"\n";
                cout<<ans.size()<<" "<<n-ans.size()<<"\n";
                for(auto i:ans){
                    cout<<i+1<<" ";
                }
                cout<<"\n";
                for(int i=0;i<n;i++){
                    if(ans.find(i)==ans.end()){
                        cout<<i+1<<" ";
                    }
                }
                cout<<"\n";
                return;
            }
            ans.clear();
            component.clear();
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++){
        ans.clear();
        order.clear();
        component.clear();
       	solve();
    }   
}