#pragma GCC optimize("Ofast")

#include <vector>
#include <iostream>
#include <algorithm>
#include <complex>
#include <set>
// #include <bits/stdc++.h>

using namespace std;

#define fst first
#define snd second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back

#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef long double ld;

// mt19937 mt_rand(chrono::system_clock::now().time_since_epoch().count());

const int maxn = (int)1e5 + 5;
const ll INF = (ll)4e18;

bool used[maxn][2];
vector<int> cmp[2];
bool a[51][51];

int n, m;
void dfs(int v, bool t) {
    cmp[t].pb(v);
    used[v][t] = 1;

    if (t == 0) {
        for (int i = 0; i < m; i++)
            if (a[v][i] && !used[i][1])
                dfs(i, 1);
    } else {
        for (int i = 0; i < n; i++)
            if (a[i][v] && !used[i][0])
                dfs(i, 0);
    }
}

int main() {
//    freopen("input.txt", "r", stdin);
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            a[i][j] = c == '#';
        }
    }

    bool ok = 1;
    for (int i = 0; i < n; i++) {
        if (!used[i][0]) {
            cmp[0].clear();
            cmp[1].clear();
            dfs(i, 0);

            for (int x : cmp[0])
                for (int y : cmp[1])
                    if (a[x][y] == 0)
                        ok = 0;
        }
    }

    for (int i = 0; i < m; i++)
        if (!used[i][1]) {
            cmp[0].clear();
            cmp[1].clear();
            dfs(i, 1);

            for (int x : cmp[0])
                for (int y : cmp[1])
                    if (a[x][y] == 0)
                        ok = 0;
        }
    puts(ok ? "Yes" : "No");
    return 0;
}