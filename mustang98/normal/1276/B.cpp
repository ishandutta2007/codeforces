#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111, inf = 1000111222;

vector<int> v[max_n];
int n, m, a, b;
int szsubb = 0;
int sz[max_n];
int d[max_n];
bool overb = false;
bool vis[max_n];
bool subtrb = 0;
int good_b_ch = 0;

void clr() {
    for (int i = 0; i < n; ++i) {
        v[i].clear();
        sz[i] = 0;
        d[i] = 0;
        vis[i] = 0;
    }
    overb = false;
    subtrb = 0;
    szsubb = 0;
    good_b_ch = 0;
}

void dfs(int cur, int curd) {
    vis[cur] = 1;
    sz[cur] = 1;
    d[cur] = curd;
    if (cur == b) {
        subtrb = true;
    }
    for (int i = 0; i < v[cur].size(); ++i) {
        int to = v[cur][i];
        if (vis[to] && subtrb && d[cur] > d[b] && d[to] < d[b]) {
            overb = true;
        }
        if (!vis[to]) {
            if (cur == a) {
                bool vaswisb = vis[b];
                dfs(to, curd + 1);
                sz[cur] += sz[to];
                if (vis[b] && !vaswisb) {
                    szsubb = sz[to];
                }
            } else if (cur == b) {
                overb = false;
                dfs(to, curd + 1);
                sz[cur] += sz[to];
                if (!overb) {
                    good_b_ch += sz[to];
                }
            } else {
                dfs(to, curd + 1);
                sz[cur] += sz[to];
            }
        }
    }
    if (cur == b) {
        subtrb = false;
    }
}


int main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        scanf("%d%d%d%d", &n, &m, &a, &b);
        --a, --b;
        for (int i = 0; i < m; ++i) {
            int f, t;
            scanf("%d%d", &f, &t);
            --f, --t;
            v[f].PB(t);
            v[t].PB(f);
        }
        dfs(a, 0);
        cout << 1LL * (sz[a] - szsubb - 1) * 1LL * good_b_ch << "\n";
        clr();
    }


    return 0;
}