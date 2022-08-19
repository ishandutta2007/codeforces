#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct SCC{
    int n;
    vector<vector<int> > graph;
    vector<int> vis, reach; // st is time you reach, scc is min t reachable
    vector<int> stk;
    vector<int> scc;
    vector<vector<int> > scclist;
    int t, cnt;
    SCC(int n = 0) : n(n), graph(n), vis(n), reach(n), scc(n), t(0) {}

    void dfs(int a){
        stk.push_back(a);
        vis[a] = reach[a] = t;
        t++;
        for(int v = 0; v < graph[a].size(); v++){
            int w = graph[a][v];
            if(scc[w] != -1) continue;
            if(vis[w] == 0) dfs(w);
            reach[a] = min(reach[a], reach[w]);
        }
        if(vis[a] == reach[a]){
            while(1){
                int l = stk[stk.size()-1];
                scc[l] = cnt;
                stk.pop_back();
                if(l == a) break;
            }
            cnt++;
        }
    }
    void findscc(){
        t = 1; cnt = 0;
        stk.clear();
        for(int i = 0; i < n; i++){
            vis[i] = reach[i] = 0;
            scc[i] = -1;
        }
        for(int i = 0; i < n; i++) if(vis[i] == 0) dfs(i);
        scclist.clear();
        scclist.resize(cnt);
        for(int i = 0; i < n; i++) scclist[scc[i]].push_back(i);
    }
};

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int n, m, h;
    cin >> n >> m >> h;
    int u[n];
    for(int i = 0; i < n; i++){
        cin >> u[i];
    }
    SCC f(n);
    set<pair<int,int> > g;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        if(g.find({a,b}) != g.end()) continue;
        g.insert({a,b});
        g.insert({b,a});
        if((u[a]+1) % h == u[b]){
            f.graph[a].push_back(b);
        }
        if((u[b]+1) % h == u[a]){
            f.graph[b].push_back(a);
        }        
    }
    f.findscc();
    vector<int> bad(n, 0);
    for(int i = 0; i < n; i++){
        for(int x : f.graph[i]){
            if(f.scc[i] == f.scc[x]) continue;
            bad[f.scc[i]] = 1;
        }
    }
    int best = -1;
    for(int j = 0; j < f.scclist.size(); j++){
        if(bad[j]) continue;
        if(f.scclist[j].size() > 0){
            if(best == -1 || f.scclist[j].size() < f.scclist[best].size()){
                best = j;
            }
        }
    }
    assert(best != -1);
    cout << f.scclist[best].size() << '\n';
    for(auto x : f.scclist[best]){
        cout << x + 1 << ' ';
    }
    cout << '\n';
}