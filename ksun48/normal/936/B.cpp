#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<int> edges[110000];

int vis[110000][2];
int par[110000][2];

void dfs(int a, int color, int p){
    if(vis[a][color]) return;
    vis[a][color] = 1;
    par[a][color] = p;
    for(int b : edges[a]){
        dfs(b, 1^color, a);
    }
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        vis[i][0] = vis[i][1] = 0;
        int b;
        cin >> b;
        for(int j = 0; j < b; j++){
            int a;
            cin >> a;
            edges[i].push_back(a-1);
        }
    }
    int s;
    cin >> s;
    s--;
    dfs(s, 0, -1);

    for(int j = 0; j < n; j++){
        if(edges[j].size() > 0) continue;
        if(vis[j][1] == 1){
            cout << "Win" << '\n';
            vector<int> path;
            int curj = j;
            int curcol = 1;
            while(curj != -1){
                path.push_back(curj);
                curj = par[curj][curcol];
                curcol = 1 ^ curcol;
            }
            reverse(path.begin(), path.end());
            for(int i = 0; i < path.size(); i++){
                cout << path[i] + 1 << " ";
            }
            cout << '\n';
            return 0;
        }
    }
    // check if there is a cycle;
    int ok[n];
    for(int i = 0; i < n; i++){
        ok[i] = vis[i][0] | vis[i][1];
    }
    vector<int> indeg(n, 0);
    for(int j = 0; j < n; j++){
        for(int x : edges[j]){
            if(ok[j] && ok[x]){
                indeg[x]++;
            }
        }
    }
    set<pair<int,int> > g;
    for(int j = 0; j < n; j++){
        if(ok[j]){
            g.insert({indeg[j], j});
        }
    }
    while(!g.empty()){
        pair<int,int> f = *g.begin();
        if(f.first != 0){
            cout << "Draw" << '\n';
            return 0;
        }
        g.erase(f);
        int a = f.second;
        for(int x : edges[a]){
            if(!ok[x]) continue;
            g.erase({indeg[x], x});
            indeg[x]--;
            g.insert({indeg[x], x});
        }
    }
    cout << "Lose" << '\n';

    return 0;
}