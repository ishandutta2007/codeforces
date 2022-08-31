#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<pair<int, int> > edges[110];
int main(){
    int n, m;
    cin >> n >> m;

    vector<int> deg(n, 0);
    vector<int> vis(n, 0);
    vector<int> topo;

    for(int i = 0; i < m; i++){
        int a, b;
        string c;
        cin >> a >> b >> c;
        a--; b--;
        edges[a].push_back({b, c[0]});
        deg[b]++;
    }

    int nvis = 0;
    while(nvis < n){
        for(int i = 0; i < n; i++){
            if(vis[i]) continue;
            if(deg[i] == 0){
                nvis++;
                topo.push_back(i);
                vis[i] = 1;
                for(auto r : edges[i]){
                    deg[r.first]--;
                }
            }
        }
    }

    reverse(topo.begin(), topo.end());

    LL winner[256][n][n][2];
    for(int z = 255; z >= 0; z--){
        for(int a = 0; a < n; a++){
            for(int b = 0; b < n; b++){
                int i = topo[a];
                int j = topo[b];
                for(int t = 0; t < 2; t++){
                    int win = 1^t;
                    if(t == 0){
                        for(auto r : edges[i]){
                            if(r.second < z) continue;
                            if(winner[r.second][r.first][j][t^1] == 0) win = t;
                        }
                    } else {
                        for(auto r : edges[j]){
                            if(r.second < z) continue;
                            if(winner[r.second][i][r.first][t^1] == 1) win = t;
                        }
                    }
                    winner[z][i][j][t] = win;
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(winner[0][i][j][0] == 0){
                cout << 'A';
            } else {
                cout << 'B';
            }
        }
        cout << endl;
    }
}