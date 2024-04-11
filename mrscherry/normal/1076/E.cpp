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

const int mod = 1e9 + 7;

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
int dep[300005];
int st[300005];
int ed[300005];
int rev[300005];
int ord;
void dfs(int x, int p) {
    st[x] = ++ord;
    rev[ord] = x;
    dep[x] = dep[p] + 1;
    for (int i : E[x]) {
        if (i == p) continue;
        dfs(i, x);
    }
    ed[x] = ord;
}

vector<pii> Q[300005];

struct fenwick {
    ll F[300005];
    void update(int i, ll x) {
        i++;
        while (i < 300005) {
            F[i] += x;
            i += i & -i;
        }
    }
    ll sum(int i) const {
        i++;
        ll x = 0;
        while (i) {
            x += F[i];
            i -= i & -i;
        }
        return x;
    }
} A;

ll ans[300005];
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
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int v, d, x;
        cin >> v >> d >> x;
        Q[st[v]].eb(min(dep[v] + d, n), x);
        Q[ed[v] + 1].eb(min(dep[v] + d, n), -x);
    }
    for (int i = 1; i <= n; i++) {
        for (pii j : Q[i]) {
            A.update(n - j.first, j.second);
        }
        ans[rev[i]] = A.sum(n - dep[rev[i]]);
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
}