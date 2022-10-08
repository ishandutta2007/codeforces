
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e5 + 5, M = 3e5 + 5;
int n, m, a, b;
vector<int> adj[N];
int vset[N];
int mask[N];
int sz[4];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vset[a] = 1;
    vset[b] = 2;
    sz[1] = sz[2] = 1;
    for(int x : adj[a]) {
        mask[x] = mask[x] | 1;
    }
    for(int y : adj[b]) {
        mask[y] = mask[y] | 2;
    }
    for(int i = 0; i < n; i++) {
        if(i != a && i != b) {
            switch(mask[i]) {
            case 0:
                cout << (-1) << endl;
                return 0;
            case 1:
                vset[i] = 2;
                sz[2]++;
                break;
            case 2:
                vset[i] = 1;
                sz[1]++;
                break;
            case 3:
                vset[i] = 3;
                sz[3]++;
                break;
            }
        }
    }
    // check all edges go between different sets
    for(int x = 0; x < n; x++) {
        for(int y : adj[x]) {
            if(vset[x] == vset[y]) {
                cout << (-1) << endl;
                return 0;
            }
        }
    }
    // and that number of edges = sz(v1) * sz(v2) + sz(v1) * sz(v3) + sz(v2) * sz(v3)
    // make sure sz(v3) > 0
    if(sz[1] == 0 || sz[2] == 0 || sz[3] == 0 || m != sz[1] * sz[2] + sz[2] * sz[3] + sz[3] * sz[1]) {
        cout << (-1) << endl;
        return 0;
    }else for(int i = 0; i < n; i++) {
        cout << vset[i] << " ";
    }
    cout << endl;
}