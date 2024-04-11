#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int b[nax];
vector <int> g[nax];
bool vis[nax];
vector <int> ord;
bool is_back[nax];
int back_of[nax];

void dfs(int v) {
    vis[v] = true;
    for (int to : g[v]) 
        if (!vis[to])  dfs(to);
    ord.push_back(v);
}

void solve() {
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> b[i];
    }

    int k = n, min_far = n + 1;
    for (int i = 0 ; i <= n ; ++ i) {
        if (min_far > i) {
            k = i;
        } else break;
        min_far = min(min_far, b[i + 1]);
    }

    for (int i = 0 ; i <= n + 1 ; ++ i) {
        g[i].clear();
        vis[i] = is_back[i] = false;
        back_of[i] = -1;
    }
    ord.clear();

    for (int i = 1 ; i <= n ; ++ i) {
        is_back[b[i]] = true;
    }
    for (int i = 1 ; i <= n ; ++ i) {
        if (is_back[i] && is_back[b[i]]) back_of[b[i]] = i;
    }


    for (int i = 1 ; i <= n ; ++ i) {
        if (b[i] != n + 1 && b[i]) {
            g[b[i]].push_back(i);
        }

    if (i != back_of[b[i]] && back_of[b[i]] != -1) g[i].push_back(back_of[b[i]]);

        /// b[i] depends on i
    }

    for (int i = 1 ; i <= n  ; ++ i) {
        if (!vis[i]) dfs(i);
    }
    cout << k << '\n';
    reverse(ord.begin(), ord.end());

    for (int i : ord) cout << i << ' ';
        cout << '\n';
}


int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}