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

int n, m, k;

struct edge {
    int x, c, i;
};
vector<edge> E[300005];
ll D[300005];
int par[300005];

const ll inf = 1e18;
void dijkstra() {
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    for (int i = 2; i <= n; i++) D[i] = inf;
    pq.emplace(0, 1);
    while (sz(pq)) {
        ll x, d;
        tie(d, x) = pq.top(); pq.pop();
        if (D[x] != d) continue;
        for (edge i : E[x]) {
            if (D[x] + i.c < D[i.x]) {
                D[i.x] = D[x] + i.c;
                par[i.x] = i.i;
                pq.emplace(D[i.x], i.x);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int x, y, d;
        cin >> x >> y >> d;
        E[x].pb({ y, d, i });
        E[y].pb({ x, d, i });
    }
    dijkstra();
    vector<int> ord;
    for (int i = 2; i <= n; i++) {
        ord.pb(i);
    }
    sort(ord.begin(), ord.end(), [&](int x, int y) {
        return D[x] < D[y];
    });
    vector<int> ans;
    for (int i : ord) {
        if (sz(ans) < k) {
            ans.push_back(par[i]);
        }
    }
    vsort(ans);
    cout << ans.size() << '\n';
    for (int i : ans) cout << i << ' ';
}