#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int mod = 998244353;
const int N = 2005;

string s;
int n;
vector<pii> g[N];
int color[N], cur;
int can[N];
int pw2[N];

void dfs(int v, int CAN = 0) {
    color[v] = cur;
    for (pii ed : g[v]) {
        int to, we;
        tie(to, we) = ed;
        if (!CAN && we) continue;
        if (!color[to]) {
            dfs(to, CAN);
        }
    }
}

void clr() {
    for (int v = 0; v < 2 * n; v++) {
        g[v].clear();
    }
}

int ty[N];
int flg;

void go(int v, int cur) {
    if (flg) return;
    ty[v] = cur;
    for (pii ed : g[v]) {
        int to, we;
        tie(to, we) = ed;
        if (ty[to] == -1) {
            go(to, cur ^ we);
            continue;
        }
        if ((ty[v] ^ we) != ty[to]) {
            flg = 1;
            return;
        }
    }
}

int odd() {
    fill(ty, ty + 2 * n, -1);
    flg = 0;
    for (int v = 0; v < 2 * n; v++) {
        if (ty[v] == -1) {
            go(v, 0);
        }
    }
    return flg;
}

int main() {

    pw2[0] = 1;
    for (int i = 1; i < N; i++) {
        pw2[i] = (2ll * pw2[i - 1]) % mod;
    }

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    n = (int)s.size();

    int res = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            g[n + j + i].emplace_back(n + n - 1 - j, 0);
            g[n + n - 1 - j].emplace_back(n + j + i, 0);
        }
        for (int j = 0; j < n; j++) {
            g[j].emplace_back(n - 1 - j, 0);
            g[n - 1 - j].emplace_back(j, 0);
        }
        for (int j = 0; j + 1 <= i; j++) {
            g[n + j].emplace_back(n + j + 1, j + 1 == i);
            g[n + j + 1].emplace_back(n + j, j + 1 == i);
        }
        g[0].emplace_back(n, 1);
        g[n].emplace_back(0, 1);
        for (int j = 0; j < n; j++) {
            if (s[j] == '?') continue;
            g[j].emplace_back(n + j, s[j] - '0');
            g[n + j].emplace_back(j, s[j] - '0');
        }
        fill(color, color + 2 * n, 0);
        cur = 1;
        for (int v = 0; v < 2 * n; v++) {
            if (!color[v]) {
                dfs(v);
                cur++;
            }
        }
        int ok = 1;
        for (int v = 0; v < 2 * n; v++) {
            for (pii ed : g[v]) {
                int to, we;
                tie(to, we) = ed;
                if (we && color[to] == color[v]) {
                    ok = 0;
                    break;
                }
            }
            if (!ok) break;
        }

//        cout << n - i << " : ";
//
//        for (int v = 0; v < 2 * n; v++) {
//            for (pii ed : g[v]) {
//                cout << v << " " << ed.first << " " << ed.second << "\n";
//            }
//        }

        if (!ok) {
            clr();
            continue;
        }

        if (odd()) {
            clr();
            continue;
        }

        fill(color, color + 2 * n, 0);

        cur = 1;

        for (int v = 0; v < 2 * n; v++) {
            if (!color[v]) {
                dfs(v, 1);
                cur++;
            }
        }

        fill(can + 1, can + cur, 1);
        can[ color[0] ] = 0;
        for (int j = 0; j <= i; j++) {
            can[ color[n + j] ] = 0;
        }
        int cnt = count(can + 1, can + cur, 1);
        if ((res += pw2[cnt]) >= mod) {
            res -= mod;
        }
        clr();
    }

    cout << res << "\n";

    return 0;
}