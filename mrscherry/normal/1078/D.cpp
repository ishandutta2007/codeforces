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

const pii no = { -1, -1 };
int n;
int R[100005];
pii sm[20][100005];
pii seg[20][400005];
pii un(pii x, pii y) {
    if (x == no) return y;
    if (y == no) return x;
    if (x.fs <= x.se && y.fs <= y.se) return { min(x.fs, y.fs), max(x.se, y.se) };
    if (y.fs <= y.se) swap(x, y);
    if (x.fs <= x.se) {
        if (x.fs <= y.se) y.se = max(y.se, x.se);
        if (y.fs <= x.se) y.fs = min(y.fs, x.fs);
        if (y.fs <= y.se + 1) return { 1, n };
        return y;
    }
    x.fs = min(x.fs, y.fs);
    x.se = max(x.se, y.se);
    if (x.fs <= x.se + 1) return { 1, n };
    return x;
}

void init(int T, int i, int s, int e) {
    if (s == e) {
        seg[T][i] = sm[T][s];
        return;
    }
    int m = s + e >> 1;
    init(T, i * 2, s, m);
    init(T, i * 2 + 1, m + 1, e);
    seg[T][i] = un(seg[T][i * 2], seg[T][i * 2 + 1]);
}

pii get(int T, int i, int s, int e, int x, int y) {
    if (e < x || y < s) return no;
    if (x <= s && e <= y) return seg[T][i];
    int m = s + e >> 1;
    return un(get(T, i * 2, s, m, x, y), get(T, i * 2 + 1, m + 1, e, x, y));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    if (n == 1) {
        cout << 0;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        cin >> R[i];
        if (R[i] + R[i] + 1 >= n) sm[0][i] = { 1, n };
        else sm[0][i] = { (i + n - R[i] - 1) % n + 1, (i + R[i] - 1) % n + 1 };
    }
    init(0, 1, 1, n);
    for (int i = 1; i < 20; i++) {
        for (int j = 1; j <= n; j++) {
            pii s = sm[i - 1][j];
            if (s.fs <= s.se) {
                s = get(i - 1, 1, 1, n, s.fs, s.se);
            }
            else {
                s = un(get(i - 1, 1, 1, n, s.fs, n), get(i - 1, 1, 1, n, 1, s.se));
            }
            sm[i][j] = s;
        }
        init(i, 1, 1, n);
    }
    for (int i = 1; i <= n; i++) {
        pii s = { i, i };
        int ans = 0;
        for (int j = 20; j--; ) {
            pii r;
            if (s.fs <= s.se) r = get(j, 1, 1, n, s.fs, s.se);
            else r = un(get(j, 1, 1, n, s.fs, n), get(j, 1, 1, n, 1, s.se));
            if (r.fs != 1 || r.se != n) {
                ans |= 1 << j;
                s = r;
            }
        }
        cout << ans + 1 << ' ';
    }
}