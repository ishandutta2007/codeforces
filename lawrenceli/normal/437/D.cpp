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
#define px real()
#define py imag()
#define rep(i, n) for (int i=0, _##i=(n); i<_##i; ++i)
#define dwn(i, n) for (int i=(n); --i>=0; )
#define repr(i, l, r) for (int i=(l), _##i=(r); i<_##i; ++i)
#define dwnr(i, l, r) for (int i=(r), _##i=(l); --i>=_##i; )
#define repi(i, n) for (__typeof((n).begin()) i=(n).begin(), _##i=n.end(); i != _##i; ++i)
#define dwni(i, n) for (__typeof((n).rbegin()) i=(n).rbegin(), _##i=(n).rend(); i!=_##i; ++i)
#define repv(i, n) for (int i=0, _##i=((n).size()); i<_##i; ++i)
#define dwnv(i, n) for (int i=((n).size()); --i>=0; )
#define sz(x) int((x).size())
#define print(x) cerr << #x << ": " << x << endl

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<double> pnt;
typedef vector<int> vi;

template <class T> T min(T a, T b, T c) { return min(a, min(b, c)); }
template <class T> T max(T a, T b, T c) { return max(a, max(b, c)); }
template <class T> void setmin(T& a, T b) { if (b < a) a = b; }
template <class T> void setmax(T& a, T b) { if (b > a) a = b; }

const int MAXN = 100100;
const int MAXM = 100100;

int n, m, v[MAXN], ar[MAXN];
bool vis[MAXN];
vector<int> adj[MAXN];
pll par[MAXN];
ll ans;

pll getpar(int a) { return par[a].fi == a ? par[a] : par[a] = getpar(par[a].fi); }
void merge(int a, int b) {
    a = getpar(a).fi, b = getpar(b).fi;
    if (a == b) return;
    par[a].fi = b;
    par[b].se += par[a].se;
}

bool cmp(int a, int b) { return v[a] > v[b]; }

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> v[i];
        ar[i] = i;
        par[i] = pll(i, 0);
    }
    sort(ar, ar+n, cmp);
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i=0; i<n; i++) {
        int x = ar[i];
        map<int, ll> mp;
        for (int j=0; j<adj[x].size(); j++) {
            if (!vis[adj[x][j]]) continue;
            pll p = getpar(adj[x][j]);
            mp[p.fi] = p.se;
        }
        ll sum = 0, sum2 = 0;
        for (typeof(mp.begin()) it = mp.begin(); it != mp.end(); it++)
            sum += it->se, sum2 += (it->se)*(it->se);
        ans += ll(v[x])*(-sum2 + sum*sum + 2*sum);
        //cout << x << ' ' << v[x] << ' ' << sum << ' ' << -sum2+sum*sum+2*sum << endl;
        vis[x] = 1;
        par[x] = pll(x, 1);
        for (int j=0; j<adj[x].size(); j++)
            if (vis[adj[x][j]]) {
                //cout << "MERGE: " << x << ' ' << adj[x][j] << endl;
                merge(x, adj[x][j]);
                //cout << "SIZE: " << getpar(x).se << endl;
            }
    }

    cout << fixed << setprecision(10) << (long double)(ans)/n/(n-1) << '\n';
    return 0;
}