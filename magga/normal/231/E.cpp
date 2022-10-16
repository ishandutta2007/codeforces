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
const long long int mod = 1e9+7;
long long int power(long long int x,long long int y){  
    long long int res = 1;
    x = x % mod;
    if (x == 0) return 0;
    while (y > 0){   
        if (y & 1)  
            res = (res*x) % mod;  
        y = y>>1;
        x = (x*x) % mod; 
    }  
    return res;
}  
long long int inv(long long int a){return power(a,mod-2);}
long long int add(long long int a,long long int b){return (a+b)%mod;}
long long int sub(long long int a,long long int b){return (a-b+mod)%mod;}
long long int mul(long long int a,long long int b){return (a*b)%mod;}
long long int divi(long long int a,long long int b){return (a*inv(b))%mod;}
ll crr[100001]{0};
vector<vector<int>>brr;
set<int>ma[100001];
ll dp[100001]{0};
void dfs1(int to,int from){
    if(crr[to]>1){
        dp[to]++;
    }
    for(auto i:brr[to]){
        if(i!=from){
            dp[i]+=dp[to];
            dfs1(i,to);
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
vector<int>arr[100001];
int vis[100001]{0};
ll val[100001]{0};
int j = 0;
int dfs(int to,int from){ 
    if(val[to]!=0){
        return 0;
    }
    if(vis[to]==1){
        j++;
        vis[to]=2;
        val[to]=j;
        return j;
    }   
    int oo = 0;
    int jo = 0;
    vis[to]=1;
    for(auto i:arr[to]){
        if(i!=from){
            jo = dfs(i,to);
            oo = max(oo,jo);
        }
    }
    if(oo==0 && vis[to]!=2){
        j++;
        val[to]=j;
        return 0;
    }else if(vis[to]!=2){
        val[to]=oo;
        if(vis[to]==1){
            return oo;
        }else{
            return 0;
        }
    }else{
        return 0;
    }
}
void pre(){}
void solve(){
    ll  n,m,u,v;cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        arr[u].pb(v);
        arr[v].pb(u);
    }
    dfs(1,0);
    vector<vector<int>>ar(j+1);
    for(int i=1;i<=n;i++){
        for(auto &j:arr[i]){
            if(val[j]!=val[i]){
                ma[val[i]].insert(val[j]);
            }
        }
    }
    for(int i=1;i<=j;i++){
        for(auto j:ma[i]){
            ar[j].pb(i);
        }
    }
    struct LCA l(ar,1);
    brr=ar;
    for(int i=1;i<=n;i++){
        crr[val[i]]++;
    }
    dfs1(1,0);
    ll ans = 0;
    ll q;cin>>q;
    for(int i=0;i<q;i++){
        cin>>u>>v;
        u=val[u];
        v=val[v];
        ans = dp[v]+dp[u]-2*dp[l.lca(u,v)];
        if(crr[l.lca(u,v)]>1){
            ans++;
        }
//        cout<<ans<<"--\n";
        cout<<power(2,ans)<<"\n";
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