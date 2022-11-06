#include <bits/stdc++.h>

#define sz(V) ((int)(V).size())
#define all(V) (V).begin(), (V).end()
#define vsort(V) sort(all(V))
#define vunique(V) (V).erase(unique(all(V)), (V).end())
#define vcomp(V) vsort(V), vunique(V)
#define fs first
#define se second
#define pp push_back
#define ep emplace_back

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

int n, m, q;
int P[200005];
int A[200005];
int L[200005];
int nxt[200005][20];
int mx[200005];
int seg[800005];

void init(int i, int s, int e) {
    if (s == e) {
        seg[i] = mx[s];
        return;
    }
    int m = s + e >> 1;
    init(i * 2, s, m);
    init(i * 2 + 1, m + 1, e);
    seg[i] = max(seg[i * 2], seg[i * 2 + 1]);
}

int get(int i, int s, int e, int x, int y) {
    if (e < x || y < s) return 0;
    if (x <= s && e <= y) return seg[i];
    int m = s + e >> 1;
    return max(get(i * 2, s, m, x, y), get(i * 2 + 1, m + 1, e, x, y));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(20);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        P[x] = i;
    }
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        A[i] = P[x];
        nxt[i][0] = L[(A[i] + 2 * n - 2) % n + 1];
        for (int j = 1; j < 20; j++) {
            nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
        }
        x = i;
        for (int j = 0; j < 20; j++) {
            if ((n - 1 >> j) & 1) x = nxt[x][j];
        }
        mx[i] = x;
        L[A[i]] = i;
    }
    init(1, 1, m);
    while (q--) {
        int x, y;
        cin >> x >> y;
        if (x <= get(1, 1, m, x, y)) cout << '1';
        else cout << '0';
    }
}