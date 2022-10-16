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
int ans[100001];
int OneCentroid(int root, const vector<vector<int>> &g, const vector<bool> &dead) {
        static vector<int> sz(g.size());
        function<void (int, int)> get_sz = [&](int u, int prev) {
                sz[u] = 1;
                for (auto v : g[u]) if (v != prev && !dead[v]) {
                        get_sz(v, u);
                        sz[u] += sz[v];
                }
        };
        get_sz(root, -1);
        int n = sz[root];
        function<int (int, int)> dfs = [&](int u, int prev) {
                for (auto v : g[u]) if (v != prev && !dead[v]) {
                        if (sz[v] > n / 2) {
                                return dfs(v, u);
                        }
                }
                return u;
        };
        return dfs(root, -1);
}
void CentroidDecomposition(const vector<vector<int>> &g) {
        int n = (int) g.size();
        vector<bool> dead(n, false);
        function<void (int,int)> rec = [&](int start,int a){
                int c = OneCentroid(start, g, dead);           //2
                dead[c] = true;                                //2
                for (auto u : g[c]) if (!dead[u]) {
                        rec(u,a+1);                                //3
                }
                /*
                        compute something with the centroid    //4
                */
                ans[c]=a;
                dead[c] = false;                              //5
        };
        rec(0,0);                                                //1
}
void pre(){}
void solve(){
    ll n,u,v;cin>>n;
    vector<vector<int>>g(n);
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        v--;u--;
        g[u].pb(v);
        g[v].pb(u);
    }
    CentroidDecomposition(g);
    for(int i=0;i<n;i++){
        if(ans[i]>25){
            cout<<"Impossible!"<<"\n";
            return;
        }
    }
    for(int i=0;i<n;i++){
        cout<<char('A'+ans[i])<<" ";
    }
    cout<<"\n";
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