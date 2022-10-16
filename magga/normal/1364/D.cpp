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
vector<int>arr[100001];
ll n,u,v,w,m,k;
ll lv[100001]{0};
bool vis[100001]{0};
vector<int> tree[2];
void dfs1(int to,int from,int lvl){
    lv[to]=lvl;
    tree[lvl%2].push_back(to);
    for(auto i:arr[to]){
        if(i!=from){
            dfs1(i,to,lvl+1);
        }
    }
} 
ll curr = 1e10;
pair<ll,pii>c;
vector<int>v1;
map<int,int>m1;
int parent[100001]{0};
void dfs(int to,int from){
    v1.push_back(to);
    m1[to]=v1.size();
    parent[to]=from;
    vis[to]=1;
    vector<pii>s;
    for(auto i:arr[to]){
        if(i==from){
            continue;
        }
        if(vis[i]==0){
            dfs(i,to);
        }else if(vis[i]==1 && m1.find(i)!=m1.end()){
            s.push_back({m1[i],i});
            if( m1[to] - m1[i]  + 1 <= curr ){
                curr =  m1[to] - m1[i]  + 1;
                c = {to,{to,i}};
            }
        }
    }
    if(s.size()>1){
        sort(s.begin(),s.end());
        for(int i=0;i<s.size()-1;i++){
            if(curr > m1[s[i+1].S]-m1[s[i].S] + 2 ){
                curr = m1[s[i+1].S] - m1[s[i].S] +2;
                c = {to,{s[i+1].S,s[i].S}};
            }
        }
    }   
    m1.erase(to);
    v1.pop_back();
}
void pre(){}
void solve(){
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        arr[u].pb(v);
        arr[v].pb(u);
    }
    if(m==n-1){
        dfs1(1,0,0);
        if(tree[0].size()<tree[1].size()){
            swap(tree[0],tree[1]);
        }
        cout<<1<<"\n";
        for(int i=0;i<(k+1)/2;i++){
            cout<<tree[0][i]<<" ";
        }
        cout<<"\n";
        return;
    }
    dfs(1,0);
    vector<ll>cycle;
    vector<vector<int>>g(n+1);
    for(int i=2;i<=n;i++){
        g[i].push_back(parent[i]);
        g[parent[i]].push_back(i);
    }
    struct LCA l (g,1);
    int oo = l.lca(c.S.F,c.S.S);
    vector<int>sup;
    int curr = c.S.S;
    if(curr==oo){
        curr=c.S.F;
    }
    while(curr!=oo){
        cycle.push_back(curr);
        curr = parent[curr];
    } 
    cycle.push_back(oo);
    if(c.F!=c.S.F){
        cycle.push_back(c.F);
    }
    if(cycle.size()<=k){
        cout<<2<<"\n";
        cout<<cycle.size()<<"\n";
        for(auto i:cycle){
            cout<<i<<" ";
        }
        cout<<"\n";
    }else{
        cout<<1<<"\n";
        int j = 0;
        for(int i=0;i<(k+1)/2;i++){
            cout<<cycle[j]<<" ";
            j+=2;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}