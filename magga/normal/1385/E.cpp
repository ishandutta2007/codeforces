#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
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
int n; // number of vertices
vector<vector<int>> adj; // adjacency list of graph
vector<int> visited;
vector<int> ans;
bool dfs(int v) {
    if(visited[v]==2){
        return 1;
    }else if(visited[v]==1){
        return 0;
    }
    int ret = 1;
    visited[v] = 1;
    for (int u : adj[v]) {
        ret&=dfs(u);
    }
    visited[v] = 2;
    ans.push_back(v);
    return ret;
}
bool topological_sort() {
    visited.assign(n,0);
    ans.clear();
    int ret = 1;
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            ret&=dfs(i);
    }
    reverse(ans.begin(), ans.end());
    return ret;
}
void pre(){}
void solve(){
    cin>>n;
    adj.clear();
    adj.resize(n);
    int m,u,v,w;cin>>m;
    vector<pii>ans1;
    vector<pii>hmm;
    for(int i=0;i<m;i++){
        cin>>w>>u>>v;
        u--;v--;
        if(w==1){
            adj[u].push_back(v);
            ans1.push_back({u+1,v+1});;
        }else{
            hmm.push_back({u+1,v+1});
        }
    }
    if(topological_sort()){
        cout<<"YES"<<"\n";
    }else{
        cout<<"NO"<<"\n";
        return;
    }
    for(auto i:ans1){
        cout<<i.F<<" "<<i.S<<"\n";
    }
    long long int pos[n+1];
    for(int i=0;i<n;i++){
        pos[ans[i]+1]=i;
    }
    for(auto i:hmm){
        if(pos[i.F]<pos[i.S]){
            cout<<i.F<<" "<<i.S<<"\n";
        }else{
            cout<<i.S<<" "<<i.F<<"\n";
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
       	solve();
    }   
}