#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<" :";
#define INF 1000000000
#define pii pair<long long int,long long int>
#define F first
#define S second
typedef long long ll;
using namespace std;
// Please write the recurances once :(
void pre(){}
struct sat{
    int n;
    vector<vector<int>> g, gt;
    vector<bool> used;
    vector<int> order, comp;
    vector<bool> assignment;

    sat(vector<vector<int>>&gr){
        g = gr;
        n = g.size();
        gt.resize(n);
        for(int i=0;i<n;i++){
            for(auto j:g[i]){
                gt[j].push_back(i);
            }
        }
    }
    void dfs1(int v) {
        used[v] = true;
        for (int u : g[v]) {
            if (!used[u])
                dfs1(u);
        }
        order.push_back(v);
    }

    void dfs2(int v, int cl) {
        comp[v] = cl;
        for (int u : gt[v]) {
            if (comp[u] == -1)
                dfs2(u, cl);
        }
    }

    bool solve_2SAT() {
        order.clear();
        used.assign(n, false);
        for (int i = 0; i < n; ++i) {
            if (!used[i])
                dfs1(i);
        }

        comp.assign(n, -1);
        for (int i = 0, j = 0; i < n; ++i) {
            int v = order[n - i - 1];
            if (comp[v] == -1)
                dfs2(v, j++);
        }

        assignment.assign(n / 2, false);
        for (int i = 0; i < n; i += 2) {
            if (comp[i] == comp[i + 1])
                return false;
            assignment[i / 2] = comp[i] > comp[i + 1];
        }
        return true;
    }
};
void solve(){
    int n,m,a,b,c;cin>>n>>m;
    pii g[n-1];
    int ans[n];
    vector<vector<int>>gr(2*n+2);
    for(int i=0;i<n-1;i++){
        cin>>a>>b>>c;
        g[i]={a,b};
        ans[i]=c;
        if(c==-1) continue;
        c = __builtin_popcount(c)%2;
        if(c==0){
            gr[2*a].push_back(2*b);
            gr[2*b].push_back(2*a);
            gr[2*a+1].push_back(2*b+1);
            gr[2*b+1].push_back(2*a+1);
        }
        if(c==1){
            gr[2*a].push_back(2*b+1);
            gr[2*b].push_back(2*a+1);
            gr[2*a+1].push_back(2*b);
            gr[2*b+1].push_back(2*a);
        }
    }
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        if(c==0){
            gr[2*a].push_back(2*b);
            gr[2*b].push_back(2*a);
            gr[2*a+1].push_back(2*b+1);
            gr[2*b+1].push_back(2*a+1);
        }
        if(c==1){
            gr[2*a].push_back(2*b+1);
            gr[2*b].push_back(2*a+1);
            gr[2*a+1].push_back(2*b);
            gr[2*b+1].push_back(2*a);
        }
    }
    sat a1(gr);
    auto apr = a1.solve_2SAT();
    if(!apr){
        cout<<"NO"<<"\n";
    }else{
        cout<<"YES"<<"\n";
        for(int i=0;i<n-1;i++){
            if(ans[i]!=-1){
                cout<<g[i].F<<" "<<g[i].S<<" "<<ans[i]<<"\n";
            }else{
                cout<<g[i].F<<" "<<g[i].S<<" "<<((a1.assignment[g[i].F])^(a1.assignment[g[i].S]))<<"\n";
            }
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