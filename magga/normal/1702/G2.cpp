#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<": ";
#define INF 1000000000
#define pii pair<long long int,long long int>
#define F first
#define S second
typedef long long ll;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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
    int n,u,v;cin>>n;
    vector<vector<int>>arr(n);
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        u--;v--;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    LCA lca(arr,0);
    int q;cin>>q;
    for(int i=0;i<q;i++){
        int k;cin>>k;
        vector<pii>v(k);
        for(int i=0;i<k;i++){
            cin>>v[i].S;
            v[i].S--;
            v[i].F = lca.height[v[i].S];
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        if(k<=2){
            cout<<"YES"<<"\n";
            continue;
        }
        bool answerExists = true;
        int lcaFA = v[0].S;
        for(auto j:v) lcaFA = lca.lca(lcaFA,j.S);
        vector<long long int>centers{v[0].S};
        for(int j=1;j<int(v.size());j++){
            bool flag = 0;
            for(auto &k:centers){
                if(flag) break;
                if(lca.lca(k,v[j].S)==v[j].S){
                    k = v[j].S;
                    flag = true;
                }
            }
            if(!flag){
                if(lca.lca(centers[0],v[j].S)==lcaFA){
                    centers.push_back(v[j].S);
                }else{
                     answerExists = false;
                    break;
                }
            }
            if(centers.size()>2){
                answerExists = false;
                break;
            }
        }
        if(answerExists) cout<<"YES"<<"\n";
        else             cout<<"NO"<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();  
}