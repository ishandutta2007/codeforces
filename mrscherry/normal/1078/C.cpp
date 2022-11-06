#include <bits/stdc++.h>

#define sz(V) ((int)(V).size())
#define all(V) (V).begin(), (V).end()
#define vsort(V) sort(all(V))
#define vunique(V) (V).erase(unique(all(V)), (V).end())
#define vcomp(V) vsort(V), vunique(V)
#define fs first
#define se second
#define pb push_back
#define eb emplace_back

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mod = 998244353;

ll gcd(ll x, ll y) { while (y) x %= y, swap(x, y); return x; }
pll operator+(pll a, pll b) { return pll(a.fs + b.fs, a.se + b.se); }
pll operator-(pll a, pll b) { return pll(a.fs - b.fs, a.se - b.se); }
ll operator*(pll a, pll b) { return a.fs * b.se - a.se * b.fs; }
template <class T> int sign(T x) { return x < 0 ? -1 : x > 0 ? 1 : 0; }
int ccw(pll a, pll b, pll c) { return sign((b - a) * (c - b)); }
template <class T> void setmin(T &x, T y) { if (x > y) x = y; }
template <class T> void setmax(T &x, T y) { if (x < y) x = y; }
template <class T> void addval(T &x, T y) { x += y; x %= mod; }
size_t getCurrentTime() { return chrono::steady_clock::now().time_since_epoch().count(); }
struct __RandomLong__ {
    mt19937_64 rnd; __RandomLong__()
    : rnd(getCurrentTime()) {}
    ll operator()(ll Min, ll Max) { return uniform_int_distribution<ll>(Min, Max)(rnd); }
    ll operator()() { return (*this)(LONG_LONG_MIN, LONG_LONG_MAX); }
} randomLong;
struct my_hash {
    static uint64_t splitmix(uint64_t x) {
        x += 0x9e3779b97f4a7c15ull;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ull;
        x = (x ^ (x >> 27)) * 0x94d049bb133111ebull;
        return x ^ (x >> 31); }
    size_t operator()(ll x) const {
        static ll T = getCurrentTime();
        return splitmix(x + T); }
};

int n;
vector<int> E[300005];
ll dp0[300005];
ll dp1[300005];
ll dp2[300005];

void update(vector<ll> &seg, int i, int s, int e, int x, ll v) {
    if (s == e) {
        seg[i] = v;
        return;
    }
    int m = s + e >> 1;
    if (x <= m) update(seg, i * 2, s, m, x, v);
    else update(seg, i * 2 + 1, m + 1, e, x, v);
    seg[i] = seg[i * 2] * seg[i * 2 + 1] % mod;
}

ll mult(vector<ll> &seg, int i, int s, int e, int x) {
    if (x < s || e < x) return seg[i];
    if (s == e) return 1;
    int m = s + e >> 1;
    return mult(seg, i * 2, s, m, x) * mult(seg, i * 2 + 1, m + 1, e, x) % mod;
}

void dfs(int x, int p) {
    dp0[x] = 1;
    dp1[x] = 0;
    dp2[x] = 1;
    vector<ll> seg(sz(E[x]) * 4);
    for (int i = 0; i < sz(E[x]); i++) {
        int v = E[x][i];
        if (v == p) {
            update(seg, 1, 0, sz(E[x]) - 1, i, 1);
            continue;
        }
        dfs(v, x);
        update(seg, 1, 0, sz(E[x]) - 1, i, (dp1[v] + dp2[v]) % mod);
        dp0[x] = dp0[x] * (dp1[v] + dp2[v]) % mod;
        dp2[x] = dp2[x] * dp2[v] % mod;
    }
    for (int i = 0; i < sz(E[x]); i++) {
        int v = E[x][i];
        if (v == p) continue;
        addval(dp1[x], mult(seg, 1, 0, sz(E[x]) - 1, i) * dp0[v] % mod);
    }
    addval(dp2[x], dp1[x]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        E[x].pb(y);
        E[y].pb(x);
    }
    dfs(1, 0);
    //for (int i = 1; i <= n; i++) cout << dp0[i] << ' ' << dp1[i] << ' ' << dp2[i] << endl;
    cout << dp2[1];
}