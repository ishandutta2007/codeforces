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
     
    int dist(int u,int v){
        int a = lca(u,v);
        return height[u]-height[a]+height[v]-height[a];
    }
};
vector<vector<int>>g(100001);
void pre(){}
void solve(){
    long long int n,u,v,a,b,k;cin>>n;
    for(long long int i=0;i<n-1;i++){
        cin>>u>>v;u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    long long int q;cin>>q;
    struct LCA lc(g);
    for(long long int i=0;i<q;i++){
        cin>>u>>v>>a>>b>>k;v--;u--;a--;b--;
        long long int dist1 = lc.dist(a,b),dist2,dist3,dist4;
        dist2=lc.dist(u,v)+1;
        dist3=lc.dist(u,a);
        dist4=lc.dist(v,b);
        if(k-dist1>=0 && (dist1-k)%2==0){
            cout<<"YES"<<"\n";
            continue;
        }
        if(k-dist3-dist4-1>=0 && (k-dist3-dist4-1)%2==0){
            cout<<"YES"<<"\n";
            continue;
        }
        if(k-dist3-dist4-dist2-1>=0 && (k-dist3-dist4-1-dist2)%2==0){
            cout<<"YES"<<"\n";
            continue;
        }
        dist4=lc.dist(u,b);
        dist3=lc.dist(v,a);
        if(k-dist3-dist4-1>=0 && (k-dist3-dist4-1)%2==0){
            cout<<"YES"<<"\n";
            continue;
        }
        if(k-dist3-dist4-dist2-1>=0 && (k-dist3-dist4-1-dist2)%2==0){
            cout<<"YES"<<"\n";
            continue;
        }
        cout<<"NO"<<"\n";
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