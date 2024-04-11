#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define rep(i,n) for(int i = 0;  i < n ; ++i)
#define REP(i,a,b) for(int i = a ; i <= b ; ++i)
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
int n,m,u,v,x,y,z;
vector<int>arr[100001];
vector<int>red;
ll a[100001];
ll dist[100001];
bool vis[100001]{0};
void ff(){
    for(int i=0;i<=n;i++)vis[i]=0;
}
void bfs(){
    queue<pair<int,int>>q;
    ff();
    for(auto to:red){
        q.push({to,0});
        vis[to]=1;
        a[to]=0;
    }    
    int ret = 0;
    while(q.size()>0){
        auto i = q.front();
        q.pop();
        a[i.first]=i.second;
        for(auto j:arr[i.first]){
            if(!vis[j]){
                q.push({j,i.second+1});
                vis[j]=1;
            }
        }
    }
}
void dfs(int to,int from){
    for(auto i:arr[to]){
        if(i!=from){
            dist[i]=dist[to]+1;
            dfs(i,to);
        }
    }
}
struct LCA {
    vector<int> height, euler, first, segtree;
    vector<bool> visited;
    int n;
    LCA(vector<vector<int>> &adj, int root = 0) {
        n = adj.size();
        height.resize(n);
        first.resize(n);
        euler.reserve(n * 2);
        visited.assign(n, false);
        dfs(adj, root);
        int m = euler.size();
        segtree.resize(m * 4);
        build(1, 0, m - 1);
    }
    void dfs(vector<vector<int>> &adj, int node, int h = 0) {
        visited[node] = true;
        height[node] = h;
        first[node] = euler.size();
        euler.push_back(node);
        for (auto to : adj[node]) {
            if (!visited[to]) {
                dfs(adj, to, h + 1);
                euler.push_back(node);
            }
        }
    }
    void build(int node, int b, int e) {
        if (b == e) {
            segtree[node] = euler[b];
        } else {
            int mid = (b + e) / 2;
            build(node << 1, b, mid);
            build(node << 1 | 1, mid + 1, e);
            int l = segtree[node << 1], r = segtree[node << 1 | 1];
            segtree[node] = (height[l] < height[r]) ? l : r;
        }
    }
    int query(int node, int b, int e, int L, int R) {
        if (b > R || e < L)
            return -1;
        if (b >= L && e <= R)
            return segtree[node];
        int mid = (b + e) >> 1;

        int left = query(node << 1, b, mid, L, R);
        int right = query(node << 1 | 1, mid + 1, e, L, R);
        if (left == -1) return right;
        if (right == -1) return left;
        return height[left] < height[right] ? left : right;
    }
    int lca(int u, int v) {
        int left = first[u], right = first[v];
        if (left > right)
            swap(left, right);
        return query(1, 0, euler.size() - 1, left, right);
    }
};
void pre(){}
void solve(){
    cin>>n>>m;
    vector<vector<int>>ar(n+1);
    for(int i=0;i<n-1;i++){
        cin>>u>>v;arr[u].pb(v);arr[v].pb(u);
        ar[u].pb(v);ar[v].pb(u);
    }
    red.pb(1);
    struct LCA l(ar,1);
    ll ans;
    ll oo = sqrt(m);
    vector<ll>v1;
    dist[1]=0;
    dfs(1,0);
    for(int i=0;i<m;i++){
        if(i%oo==0){
            bfs();
            v1.clear();
        }
        cin>>u>>v;
        if(u==1){
            red.pb(v);
            v1.pb(v);
        }else{
            ans = a[v];
            for(auto i:v1){
                ans = min(ans,dist[i]+dist[v]-2*dist[l.lca(i,v)]);
            }
            cout<<ans<<"\n";
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}