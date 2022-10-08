
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;

// if a dead-end is odd distance away, WIN
// else if a cycle is reachable, DRAW
// if no cycle is reachable and all dead-ends are even distance away, LOSE

const int N = 1e5 + 5;
int n, m, c, v, s;

vector<int> adj[N];
int vis[N][2], par[N][2];
bool cyc = false;
map<int, int> opp = {{0, 0}, {1, 2}, {2, 1}, {3, 3}};

void printpath(int x, int p) {
    if(x != s || p != 0) {
        printpath(par[x][p], !p);
    }
    cout << x + 1 << ' ';
}

void dfs(int x, int p) {
    vis[x][p] = 1;
    for(int y : adj[x]) {
        if(vis[y][!p] == 0) {
            par[y][!p] = x;
            dfs(y, !p);
        }else if(vis[y][!p] == 1) cyc = true;
    }
    vis[x][p] = 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    rep(i, 0, n) {
        cin >> c;
        while(c--) {
            cin >> v;
            v--;
            adj[i].push_back(v);
        }
    }
    cin >> s;
    s--;
    dfs(s, 0);
    rep(i, 0, n) {
        if(adj[i].empty() && vis[i][1] == 2) {
            cout << "Win\n";
            printpath(i, 1);
            cout << '\n';
            return 0;
        }
    }
    if(cyc) {
        cout << "Draw\n";
    }else {
        cout << "Lose\n";
    }
}