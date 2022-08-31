#include <bits/stdc++.h>
using namespace std;
struct seg {
    int t;
    int l;
    int r;
    int v;
};
int n, q;
vector < int > g[52];
seg m[102];
bool used[102];
int par[102];
bool kun ( int v) {
    //cout << v;
    if ( used[v] == true) return false;
    used[v] = true;
    for ( int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if ( par[to] == 0 || kun(par[to])) {
            par[to] = v;
            return true;
        }
    }
    return false;
}
bool t[105];
int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> q;
    //vector < int > u;
    //for ( int i = 1; i <= n; i++) u.push_back(i);
    for ( int i = 1; i <= q; i++) {
        cin >> m[i].t >> m[i].l >> m[i].r >> m[i].v;
    }
    bool mark;
    for ( int i = 1; i <= n; i++) {
        for ( int j = 1; j <= n; j++) {
            mark = true;
            for ( int it = 1; it <= q; it++) {
                if ( j >= m[it].l && j <= m[it].r) {
                    if ( m[it].t == 1) {
                        if ( m[it].v > i) {
                            mark = false;
                        }
                    }
                    else {
                        if ( m[it].v < i) {
                            mark = false;
                        }
                    }
                }
            }
            if (mark) {
                    g[i].push_back(j);
                    t[j] = true;
            }
        }
    }
    for ( int i = 1; i <= n; i++) {
        if ( !t[i]) {
            cout << -1;
            return 0;
        }
    }
    int cnt[n + 1];
    for ( int i = 1; i <= n; i++) {
        cnt[i] = 0;
    }
    for ( int it = 1; it <= max(n, 30); it++) {
        for ( int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) used[j] = false;
            kun(i);
        }
    }
    int ans = 0;
    for ( int i = 1; i <= n; i++) {
        cnt[par[i]]++;
    }
    for ( int i = 1; i <= n; i++) {
        //cout << cnt[i] << endl;
        ans += cnt[i] * cnt[i];
    }
    cout << ans;
    return 0;
}