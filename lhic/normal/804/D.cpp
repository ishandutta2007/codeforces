#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>
#include <functional>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef double ld;

using namespace std;

#ifndef LOCAL
#define cerr _cer
struct _cert
{
    template <typename T> _cert& operator << (T) { return *this; }
};
_cert _cer;
#endif

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}
const int MAXN = 120000;

int n, m;
vector<int> vv;
int cl[MAXN];
int was[MAXN];
int sz[MAXN];
int dp[MAXN];
vector<int> eds[MAXN];
int dd[MAXN];

void dfs1(int v, int p, int c) {
    vv.push_back(v);
    cl[v] = c;
    was[v] = 1;
    ++sz[c];
    for (int u: eds[v])
        if (u != p)
            dfs1(u, v, c);
}

pair<int, int> dfs2(int v, int p) {
    pair<int, int> ans = make_pair(0, v);
    for (int u: eds[v]) {
        if (u != p) {
            pair<int, int> tmp = dfs2(u, v);
            ++tmp.first;
            ans = max(ans, tmp);
        }
    }
    return ans;
}

void dfs3(int v, int p, int d) {
    dp[v] = max(dp[v], d);
    for (int u: eds[v]) {
        if (u != p)
            dfs3(u, v, d + 1);
    }
}

vector<ld> go[MAXN];
vector<ld> pr[MAXN];
vector<ld> pr2[MAXN];

void solve(int v, int c) {
    vv.clear();
    dfs1(v, -1, c);
    int x = dfs2(v, -1).second;
    pair<int, int> y = dfs2(x, -1);
    dd[c] = y.first;
    go[c].resize(sz[c]);
    pr[c].resize(sz[c]);
    pr2[c].resize(sz[c]);
    dfs3(x, -1, 0);
    dfs3(y.second, -1, 0);
    for (int i: vv)
        ++go[c][dp[i]];
    for (int i = 0; i < sz[c]; ++i)
        go[c][i] /= sz[c];
    ld now = 0;
    ld now2 = 0;
    for (int i = sz[c] - 1; i >= 0; --i) {
        now += go[c][i];
        now2 += now;
        pr[c][i] = now;
        pr2[c][i] = now2;
    }
}

int cc;
map<pair<int, int>, ld> mm;

int main() {
    int q;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a, --b;
        eds[a].push_back(b);
        eds[b].push_back(a);
    }
    for (int i = 0; i < n; ++i) {
        if (!was[i]) {
            solve(i, cc++);
        }
    }
    for (int i = 0; i < q; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a, --b;
        a = cl[a];
        b = cl[b];
        if (a == b) {
            printf("-1\n");
            continue;
        }
        if (sz[a] > sz[b])
            swap(a, b);
        if (sz[a] == sz[b] && a > b)
            swap(a, b);
        if (mm.count(make_pair(a, b))) {
            printf("%.10f\n", (double)mm[make_pair(a, b)]);
            continue;
        }
        int mn = max(dd[a], dd[b]);
        ld ans = 0;
        for (int i = 0; i < sz[a]; ++i) {
            int nd = mn + 1 - (i + 1);
            if (nd <= 0) {
                ans += go[a][i] * (pr2[b][0] + i);
            }
            else if (nd < sz[b]) {
                ans += go[a][i] * (pr2[b][nd] + mn);
            }
            else {
                ans += go[a][i] * mn;
            }
        }
        printf("%.10f\n", (double)ans);
        mm[make_pair(a, b)] = ans;
    }
    return 0;
}