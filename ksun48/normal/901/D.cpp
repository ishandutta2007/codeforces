#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<int> edges[110000];
LL c[110000];
pair<int,int> r[110000];
map<pair<int,int>, LL> wgt;

int color[110000];
vector<int> oddcyc;
int done = 0;
int dfs(int a, int col){
    if(done) return -1;
    if(color[a] == 1-col){
        return a;
    }
    if(color[a] == col) return -1;
    color[a] = col;
    for(int j = 0; j < edges[a].size(); j++){
        int k = dfs(edges[a][j], 1-col);
        if(done) return -1;
        if(k != -1){
            oddcyc.push_back(a);
            if(k == a) done = 1;
            return k;
        }
    }
    return -1;
}

int vis[110000];
int cyc[110000];

void setwgt(int a, int b, LL w){
    wgt[make_pair(a,b)] = w;
    wgt[make_pair(b,a)] = w;
}

void dfs2(int par, int a){
    if(vis[a]) return;
    vis[a] = 1;
    for(int j = 0; j < edges[a].size(); j++){
        dfs2(a, edges[a][j]);
    }
    if(par != -1){
        setwgt(a,par,c[a]);
        c[par] -= c[a];
        c[a] -= c[a];
    }
}

void dfs3(int par, int a){
    if(vis[a]) return;
    if(par != -1 && cyc[a]) return;
    vis[a] = 1;
    for(int j = 0; j < edges[a].size(); j++){
        dfs3(a, edges[a][j]);
    }
    if(par != -1){
        setwgt(a,par,c[a]);
        //cout << a << " " << par << " " << c[a] << endl;
        c[par] -= c[a];
        c[a] -= c[a];
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        r[i].first = a; r[i].second = b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    for(int i = 0; i < n; i++){
        color[i] = -1;
        vis[i] = cyc[i] = 0;
    }

    dfs(0,0);
    /*for(int j = 0; j < oddcyc.size(); j++){
        cout << oddcyc[j] << endl;
    }*/
    if(oddcyc.size() == 0){
        LL sums[2];
        sums[0] = sums[1] = 0;
        for(int j = 0; j < n; j++){
            sums[color[j]] += c[j];
        }
        if(sums[0] != sums[1]){
            cout << "NO" << endl;
            return 0;
        }
        dfs2(-1,0);
        cout << "YES" << endl;
        for(int j = 0; j < m; j++){
            cout << wgt[r[j]] << endl;
        }
        return 0;
    }
    for(int i = 0; i < oddcyc.size(); i++){
        cyc[oddcyc[i]] = 1;
    }
    for(int i = 0; i < oddcyc.size(); i++){
        dfs3(-1, oddcyc[i]);
    }
    LL lastedge = 0;
    for(int i = 0; i < oddcyc.size(); i++){
        if(i % 2 == 0){
            lastedge += c[oddcyc[i]];
        } else {
            lastedge -= c[oddcyc[i]];
        }
    }
    lastedge /= 2;
    setwgt(oddcyc[0], oddcyc[oddcyc.size()-1], lastedge);
    for(int i = 0; i < oddcyc.size() - 1; i++){
        lastedge = c[oddcyc[i]] - lastedge;
        setwgt(oddcyc[i], oddcyc[i+1], lastedge);
    }
    cout << "YES" << endl;
    for(int j = 0; j < m; j++){
        cout << wgt[r[j]] << endl;
    }
    return 0;
}