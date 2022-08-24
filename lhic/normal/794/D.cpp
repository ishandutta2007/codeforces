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
#include <random>
#include <ctime>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;

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

typedef unsigned long long ull;

mt19937_64 rnd(time(NULL));
const int MAXN = 310000;
ull rn[MAXN];
ull go[MAXN];
map<ull, int> mm;
int cc;
vector<pair<int, int> > ed;
vector<int> eds[MAXN];
int cl[MAXN];
int dd[MAXN];
int was[MAXN];
int n, m;
int us[MAXN];

void dfs1(int v, int d) {
    was[v] = 1;
    dd[v] = d;
    if (us[d]) {
        cout << "NO\n";
        exit(0);
    }
    us[d] = 1;
    for (int u: eds[v]) {
        if (!was[u])
            dfs1(u, d + 1);
    }
}

int main() {
    for (int i = 0; i < MAXN; ++i)
        rn[i] = rnd();
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        go[i] = rn[i];
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a, --b;
        ed.push_back(make_pair(a, b));
        go[a] ^= rn[b];
        go[b] ^= rn[a];
    }
    for (int i = 0; i < n; ++i) {
        ull hs = go[i];
        if (mm.count(hs)) {
            cl[i] = mm[hs];
        }
        else {
            cl[i] = mm[hs] = cc++;
        }
    }
    for (int i = 0; i < ed.size(); ++i) {
        int a, b;
        a = ed[i].first;
        b = ed[i].second;
        a = cl[a];
        b = cl[b];
        if (a != b) {
            eds[a].push_back(b);
            eds[b].push_back(a);
        }
    }
    for (int i = 0; i < cc; ++i) {
        sort(eds[i].begin(), eds[i].end());
        eds[i].resize(unique(eds[i].begin(), eds[i].end()) - eds[i].begin());
    }
    int st = -1;
    for (int i = 0; i < n; ++i) {
        if (eds[i].size() == 1)
            st = i;
    }
    if (cc == 1)
        st = 0;
    if (st == -1) {
        cout << "NO\n";
        return 0;
    }
    dfs1(st, 1);
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        printf("%d ", dd[cl[i]]);
    }
    printf("\n");
    return 0;
}