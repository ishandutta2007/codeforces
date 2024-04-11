#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define fi first
#define se second
#define rep(i, n) for (int i=0, _##i=(n); i<_##i; ++i)
#define dwn(i, n) for (int i=(n); --i>=0; )
#define repr(i, l, r) for (int i=(l), _##i=(r); i<_##i; ++i)
#define dwnr(i, l, r) for (int i=(r), _##i=(l); --i>=_##i; )
#define repi(i, n) for (__typeof((n).begin()) i=(n).begin(), _##i=n.end(); i != _##i; ++i)
#define dwni(i, n) for (__typeof((n).rbegin()) i=(n).rbegin(), _##i=(n).rend(); i!=_##i; ++i)
#define repv(i, n) for (int i=0, _##i=((n).size()); i<_##i; ++i)
#define dwnv(i, n) for (int i=((n).size()); --i>=0; )
#define print(x) cerr << #x << ": " << x << endl

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<ll> pnt;
typedef vector<int> vi;

template <class T> T min(T a, T b, T c) { return min(a, min(b, c)); }
template <class T> T max(T a, T b, T c) { return max(a, max(b, c)); }
template <class T> void setmin(T& a, T b) { if (b < a) a = b; }
template <class T> void setmax(T& a, T b) { if (b > a) a = b; }

typedef pair<pnt, int> ppi;

const int MAXN = 100100;
const int MAXLG = 18;

int n, par[MAXN], dep[MAXN], jump[MAXN][MAXLG];
vector<int> adj[MAXN];
pnt pnts[MAXN];
deque<ppi> dq;

ll cross(pnt p1, pnt p2) { return imag(conj(p1) * p2); }

bool bad(pnt p) {
    pnt p1 = dq[0].fi, p2 = dq[1].fi;
    return cross(p1 - p, p2 - p1) > 0;
}

void dfs(int cur, int p) {
    dep[cur] = dep[p] + 1;
    for (int i=0; i<adj[cur].size(); i++) {
        int nxt = adj[cur][i];
        dfs(nxt, cur);
    }
}

void initlca() {
    for (int i=0; i<n; i++) jump[i][0] = par[i];
    for (int k=1; k<MAXLG; k++)
        for (int i=0; i<n; i++)
            jump[i][k] = jump[jump[i][k-1]][k-1];
}

int lca(int a, int b) {
    if (dep[a] > dep[b]) swap(a, b);
    for (int k=MAXLG-1; k>=0; k--)
        if (dep[jump[b][k]] >= dep[a])
            b = jump[b][k];

    if (a == b) return a;
    for (int k=MAXLG-1; k>=0; k--)
        if (jump[a][k] != jump[b][k])
            a = jump[a][k], b = jump[b][k];
    return par[a];
}

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n; i++) cin >> pnts[i].real() >> pnts[i].imag();

    for (int i=n-1; i>=0; i--) {
        while (dq.size() >= 2 && bad(pnts[i])) dq.pop_front();
        if (dq.empty()) par[i] = n-1;
        else par[i] = dq.front().se;
        if (i != n-1) adj[par[i]].push_back(i);
        dq.push_front(ppi(pnts[i], i));
    }

    dfs(n-1, n-1);
    initlca();

    int m; cin >> m;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        cout << lca(a, b) + 1 << ' ';
    }

    return 0;
}