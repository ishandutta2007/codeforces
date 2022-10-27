#include<bits/stdc++.h>
using namespace std;
int const nax = 1e6 + 10;
int n, m;
vector<int> a[nax];
vector<int> b[nax];

bool vis[nax];

int id[nax];
int cycle_len[nax];
int dist[nax];

int to_id (int i, int j) {
    return i * m + j;
}


void solve () {

    cin >> n >> m;

    const int sz = n * m;

    vector<string> s(n), b(n);
    vector<int> to_bfs;
    int cycle_id = 0;

    for (int i = 0 ; i < n ; ++ i)
        cin >> b[i];

    for (int i = 0 ; i < n ; ++ i)
        cin >> s[i];

    fill(vis, vis + sz, false);
    fill(id, id + sz, 0);


    auto nxt = [&] (int x) -> int {
        int i = x / m, j = x % m;
        char c = s[i][j];
        if (c == 'U') -- i;
        else if (c == 'D') ++ i;
        else if (c == 'R') ++ j;
        else if (c == 'L') -- j;
        else throw;
        return to_id(i, j);
    };

    for (int i = 0 ; i < n;  ++ i) {
        for (int j = 0 ; j < m ; ++ j) {
            int idx = to_id(i, j);
            int to = nxt(idx);
            a[to].push_back(idx);
        }
    }

    for (int i = 0 ; i < sz ; ++ i) {
        if (vis[i]) continue;

        vector<int> st;
        int x = i;
        while (true) {

            if (id[x] > 0) {
                for (int j : st)
                    id[j] = id[x];
                    break;
            }

            if (vis[x]) {
                id[x] = ++ cycle_id;
                for (int j : st)
                    id[j] = cycle_id;

                to_bfs.push_back(x);

                int len = 1;
                while (st.back() != x) {
                    st.pop_back();
                    ++ len;
                }

                cycle_len[cycle_id] = len;

                break;
            }

            st.push_back(x);
            vis[x] = true;
            x = nxt(x);
        }
    }

    fill(dist , dist + sz, nax);


    for (int i = 0 ; i < sz ; ++ i) {
        ::b[id[i]].push_back(i);
    }


    for (int v : to_bfs) {
        static int q[nax];
        int topQ = 0;
        q[topQ ++] = v;
        dist[v] = 0;

        for (int i = 0 ; i < topQ ; ++ i) {
            int cur = q[i];

            for (int u : a[cur]) {
                if (dist[cur] + 1 < dist[u]) {
                    dist[u] = dist[cur] + 1;
                    q[topQ ++] = u;
                }
            }
        }
    }

    int ans = 0, ans2 = 0;

    for (int i = 1 ; i <= cycle_id ; ++ i) {
        int len = cycle_len[i];
        ans += len;

        static bool has[nax];
        fill(has, has + len, false);

        for (int j : ::b[i]) {
            int x = j / m, y = j % m;

            /// 0 is black
            if (b[x][y] == '0') {
                has[dist[j] % len] = true;
            }
        }

        ans2 += accumulate(has, has + len, 0);
    }


    for (int i = 0 ; i < sz ; ++ i) {
        a[i].clear();
        ::b[i].clear();
    }
    cout << ans << ' ' << ans2 << '\n';
}

int main () {


    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}