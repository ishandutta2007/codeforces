#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <functional>
#include <cstring>
#include <cassert>
#include <numeric>

//#define FAST_ALLOCATOR_MEMORY 2e8
//#include "optimization.h"

using namespace std;

typedef long long ll;
typedef long double ld;
const ll md = (ll)1e9 + 7, inf = (ll)1e18;

vector<vector<int>> g;
vector<int> mark, us, wh, bl;
int sz = 1;

void add(ll x, int k, int c) {
    int v = 0;
    for (int i = 0; i < k; i++) {
        int whr = 31 - i;
        int to = (x >> whr) & 1;
        if (g[v][to] == -1) {
            g.push_back({-1, -1});
            mark.push_back(0);
            //us.push_back()
            wh.push_back(0);
            bl.push_back(0);
            g[v][to] = sz++;
        }
        v = g[v][to];
    }
    if (mark[v] && mark[v] != c) {
        cout << "-1\n";
        exit(0);
    }
    mark[v] = c;
}

void dfs(int v) {
    wh[v] = mark[v] == 1;
    bl[v] = mark[v] == -1;

    for (int u : g[v]) {
        if (u == -1)
            continue;
        dfs(u);
        wh[v] += wh[u], bl[v] += bl[u];
    }

    if (mark[v] == 1 && bl[v]) {
        cout << "-1\n";
        exit(0);
    }
    if (mark[v] == -1 && wh[v]) {
        cout << "-1\n";
        exit(0);
    }
}

vector<pair<int,ll>> ans;

void doit(int v, ll cur, int d) {
    if (!wh[v]) {
        ans.push_back({d, cur});
        return;
    }

    for (int i = 0; i < 2; i++) {
        int u = g[v][i];
        if (u != -1)
            doit(u, cur + i * (1ll << (31 - d)), d + 1);
    }
}

pair<int,ll> f(string s) {
    ll cur = 0;
    ll t = 0;
    reverse(s.begin(), s.end());
    while (s.size()) {
        char c = s.back();
        s.pop_back();
        if (c == '.') {
            cur *= 1 << 8;
            cur += t;
            t = 0;
            continue;
        }
        if (c == '/') {
            cur *= 1 << 8;
            cur += t;
            t = 0;
            break;
        }
        t = (t * 10) + c - '0';
    }
    if (!s.size())
        return { 32, cur * (1 << 8) + t };
    else {
        while (s.size()) {
            char c = s.back();
            s.pop_back();
            t = (t * 10) + c - '0';
        }
        return { t, cur };
    }
}

string nf(pair<int,ll> p) {
    string ret = "";
    for (int i = 0; i < 4; i++) {
        int c = 0;
        for (int j = i * 8; j < (i + 1) * 8; j++)
            c += ((p.second >> j) & 1) * (1 << (j - (i * 8)));
        string t = to_string(c);
        reverse(t.begin(), t.end());
        if (i)
            ret += ".";
        ret += t;
    }
    reverse(ret.begin(), ret.end());
    return ret + "/" + to_string(p.first);
}

int main() {
    iostream::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

#ifdef LOCAL
    freopen("C:\\Users\\aytel\\CLionProjects\\common\\input.txt", "r", stdin);
    freopen("C:\\Users\\aytel\\CLionProjects\\common\\output.txt", "w", stdout);
#endif

    g.resize(1, {-1, -1});
    mark.resize(1, 0);
    wh.resize(1, 0);
    bl.resize(1, 0);

    int n;
    cin >> n;

    while (n--) {
        string s;
        cin >> s;
        bool ch = s[0] == '-';
        s = s.substr(1, s.length() - 1);
        pair<int,ll> cur = f(s);
        add(cur.second, cur.first, (ch ? -1 : 1));
    }

    dfs(0);

    if (!bl[0]) {
        cout << "0\n";
        return 0;
    }

    //us.assign(33, unordered_map<int,ll>());
    doit(0, 0, 0);

    cout << ans.size() << '\n';

    for (auto &c : ans)
        cout << nf(c) << '\n';

    return 0;
}