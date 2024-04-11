
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

const int N = 5005;
int n, m, u, v, c[3];
vi adj[N];
bool vis[N], cyc = false;
int col[N], par[N], cnt[N][2], choice[N][N], compchoice[N];

void dfs(int x) {
    vis[x] = true;
    cnt[par[x]][col[x]]++;
    for(int y : adj[x]) {
        if(!vis[y]) {
            col[y] = !col[x];
            par[y] = par[x];
            dfs(y);
        }else if(col[x] == col[y]) {
            cyc = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> c[0] >> c[1] >> c[2];
    rep(i, 0, m) {
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int k = 1;
    rep(i, 0, n) {
        if(!vis[i]) {
            par[i] = k++;
            dfs(i);
        }
    }
    if(cyc) {
        cout << "NO\n";
        return 0;
    }
    rep(i, 0, k + 1) {
        fill(choice[i], choice[i] + n, -1);
    }
    choice[0][0] = 0;
    rep(i, 1, k + 1) {
        rep(j, 0, c[1] + 1) {
            if(cnt[i][0] <= j && choice[i - 1][j - cnt[i][0]] != -1) {
                choice[i][j] = 0;
            }else if(cnt[i][1] <= j && choice[i - 1][j - cnt[i][1]] != -1) {
                choice[i][j] = 1;
            }
        }
    }
    if(choice[k][c[1]] == -1) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    int i = k, j = c[1];
    while(i > 0) {
        compchoice[i] = choice[i][j];
        j -= cnt[i][compchoice[i]];
        i--;
    }
    rep(i, 0, n) {
        if(compchoice[par[i]] == col[i]) {
            cout << 2;
        }else if(c[0] > 0) {
            cout << 1;
            c[0]--;
        }else {
            cout << 3;
        }
    }
    cout << '\n';
}