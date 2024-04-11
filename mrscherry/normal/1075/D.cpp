#include <bits/stdc++.h>

#define szv(V) ((int)(V).size())
#define allv(V) (V).begin(), (V).end()
#define sortv(V) sort(allv(V))
#define uniquev(V) (V).erase(unique(allv(V)), (V).end())
#define compv(V) sortv(V), uniquev(V)
#define fs first
#define se second
#define pb push_back
#define eb emplace_back

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mod = 1e9 + 7;
const ll inf = 4e18 + 5;

ll gcd(ll x, ll y) { while (y) x %= y, swap(x, y); return x; }
pll operator+(pll a, pll b) { return pll(a.fs + b.fs, a.se + b.se); }
pll operator-(pll a, pll b) { return pll(a.fs - b.fs, a.se - b.se); }
ll operator*(pll a, pll b) { return a.fs * b.se - a.se * b.fs; }
template <class T> int sign(T x) { return x < 0 ? -1 : x > 0 ? 1 : 0; }
int ccw(pll a, pll b, pll c) { return sign((b - a) * (c - b)); }
template <class T> void setmin(T &x, T y) { if (x > y) x = y; }
template <class T> void setmax(T &x, T y) { if (x < y) x = y; }
template <class T> void addval(T &x, T y) { x += y; x %= mod; }

vector<int> edge[1005];
int chx[1005], chy[1005];

int dfs(int x, int p) {
    if (chx[x]) return x;
    for (int i : edge[x]) {
        if (i == p) continue;
        int ret = dfs(i, x);
        if (ret != -1) return ret;
    }
    return -1;
}

void solve() {
    int n, k1, k2;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        edge[i].clear();
        chx[i] = chy[i] = 0;
    }
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    }
    cin >> k1;
    int xn, yn;
    for (int i = 0; i < k1; i++) {
        int x;
        cin >> x;
        xn = x;
        chx[x] = 1;
    }
    cin >> k2;
    for (int i = 0; i < k2; i++) {
        int x;
        cin >> x;
        yn = x;
        chy[x] = 1;
    }
    cout << "B " << yn << endl;
    int ynx;
    cin >> ynx;
    if (chx[ynx]) cout << "C " << ynx << endl;
    else {
        int ret = dfs(ynx, 0);
        cout << "A " << ret << endl;
        int lst;
        cin >> lst;
        if (chy[lst]) cout << "C " << ret << endl;
        else cout << "C -1" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
}