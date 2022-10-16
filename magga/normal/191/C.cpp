#include<bits/stdc++.h>
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
void pre(){}
int val[100001]{0};
int ans[100001]{0};
vector<int>arr[100001];
map<pair<int,int>,int>m1;
int dfs(int to,int from){
    int ret = 0;
    for(auto i:arr[to]){
        if(i!=from){
            auto p = dfs(i,to);
            ret+=p;
            ans[m1[{min(i,to),max(i,to)}]]=p;
        }
    }
    ret+=val[to];
    return ret;
}
void solve(){
    int n,u,v;cin>>n;
    vector<vector<int>>g(n);
    for(int i=0;i<n-1;i++){
        cin>>u>>v;u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
        arr[u].push_back(v);
        arr[v].push_back(u);
        m1[{min(u,v),max(u,v)}]=i;  
    }
    struct LCA lc(g,0);
    int m;cin>>m;
    for(int i=0;i<m;i++){
        cin>>u>>v;u--;v--;
        val[u]++;
        val[v]++;
        auto j =lc.lca(u,v);
        val[j]-=2;
    }
    dfs(0,-1);
    for(int i=0;i<n-1;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
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