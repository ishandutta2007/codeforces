#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct SCC{
    vector<int> used;
    vector<vector<int> > g2;

    void dfs1(vector<int>*g, int x, vector<int>&ns){
        if (used[x]==1) return;
        used[x]=1;
        for (int nx:g[x]){
            g2[nx].push_back(x);
            dfs1(g, nx, ns);
        }
        ns.push_back(x);
    }

    void dfs2(int x, vector<int>&co){
        if (used[x]==2) return;
        used[x]=2;
        co.push_back(x);
        for (int nx:g2[x]){
            dfs2(nx, co);
        }
    }

    SCC(vector<int>*g, int n, vector<vector<int> >&ret):used(n+1),g2(n+1){
        vector<int> ns;
        for (int i=1;i<=n;i++){
            dfs1(g, i, ns);
        }
        for (int i=n-1;i>=0;i--){
            if (used[ns[i]]!=2){
                ret.push_back(vector<int>());
                dfs2(ns[i], ret.back());
            }
        }
    }
};

ll c[101010];
vector<int> g[101010];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>c[i];
    }
    int m;
    cin>>m;
    for (int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
    }
    vector<vector<int> > sc;
    SCC(g, n, sc);
    ll vs=1;
    ll cost=0;
    for (auto co:sc){
        ll mi=1e9;
        ll mis=0;
        for (int t:co){
            if (c[t]<mi){
                mi=c[t];
                mis=1;
            }
            else if(c[t]==mi){
                mis++;
            }
        }
        cost+=mi;
        vs*=mis;
        vs%=(ll)(1e9+7);
    }
    cout<<cost<<" "<<vs<<endl;
}