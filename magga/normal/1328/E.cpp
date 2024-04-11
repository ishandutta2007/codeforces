#include<bits/stdc++.h>
using namespace std;
void pre(){}
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
vector<set<int>>g(2000001);
long long int depth[2000001];
bool visited[2000001]{0};
void dfs(int j){
    for(auto i:g[j]){
        if(visited[i]) continue;
        visited[i]=1;
        depth[i]=depth[j]+1;
        dfs(i);
    }
}
void solve(){
    int n,u,v,q;cin>>n>>q;
    vector<vector<int>>g1(n);
    for(long long int i=0;i<n-1;i++){
        cin>>u>>v;u--;v--;
        g[v].insert(u);
        g[u].insert(v);
        g1[v].push_back(u);
        g1[u].push_back(v);
    }
    depth[0]=0;
    visited[0]=1;
    dfs(0);
    struct LCA lca(g1);
    for(int i=0;i<q;i++){
        long long int k;cin>>k;
        pair<long long int,long long int> arr[k];
        for(long long int i=0;i<k;i++){
            cin>>arr[i].second;
            arr[i].second--;
            arr[i].first=depth[arr[i].second];
        }
        sort(arr,arr+k);
        bool flag = 1;
        long long int ref = arr[k-1].second;
        for(int i=k-2;i>=0;i--){
            auto p = lca.lca(ref,arr[i].second);
            if(g[p].find(arr[i].second)==g[p].end() && p != arr[i].second ){
                flag=0;
                //cout<<p<<"\n";
                break;
            }
        }
        if(flag){
            cout<<"YES"<<"\n";
        }else{
            cout<<"NO"<<"\n";
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    //cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}