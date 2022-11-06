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

ll DP[2005][2005]; // Count / Overlap
ll pw[2005];

int seg1[8005];
int seg2[8005];
void init(int i, int s, int e) {
    seg1[i] = seg2[i] = e - s + 1;
    if (s == e) return;
    int m = s + e >> 1;
    init(i * 2, s, m);
    init(i * 2 + 1, m + 1, e);
}

void update(int seg[], int i, int s, int e, int x, int v) {
    seg[i] += v;
    if (s == e) return;
    int m = s + e >> 1;
    if (x <= m) update(seg, i * 2, s, m, x, v);
    else update(seg, i * 2 + 1, m + 1, e, x, v);
}

ll getsum(int seg[], int i, int s, int e, int x, int y) {
    if (e < x || y < s) return 0;
    if (x <= s && e <= y) return seg[i];
    int m = s + e >> 1;
    return getsum(seg, i * 2, s, m, x, y) + getsum(seg, i * 2 + 1, m + 1, e, x, y);
}

int n;
int A[2005][2005];
int cnt1[2005], cnt2[2005];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    DP[0][0] = 1;
    for (int i = 1; i <= 2000; i++) {
        DP[i][0] = i * DP[i - 1][0] % mod;
        for (int j = 1; j <= i; j++) {
            addval(DP[i][j], (i - j) * DP[i - 1][j - 1] % mod);
            if (j > 1) addval(DP[i][j], (j - 1) * DP[i - 1][j - 2] % mod);
        }
    }
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> A[i][j];
        }
    }
    pw[0] = 1;
    for (int i = 1; i <= n; i++) pw[i] = pw[i - 1] * DP[n][n] % mod;
    ll ans = 0;
    init(1, 1, n);
    for (int i = 1; i <= n; i++) {
        addval(ans, getsum(seg2, 1, 1, n, 1, A[1][i] - 1) * pw[n - 1] % mod * DP[n - i][0] % mod);
        update(seg2, 1, 1, n, A[1][i], -1);
    }
    for (int i = 2; i <= n; i++) {
        int ov = n;
        for (int j = 1; j <= n; j++) cnt1[j] = cnt2[j] = 1;
        init(1, 1, n);
        for (int j = 1; j <= n; j++) {
            ov -= cnt2[A[i - 1][j]];
            if (cnt1[A[i - 1][j]] && cnt2[A[i - 1][j]]) update(seg1, 1, 1, n, A[i - 1][j], -1);
            cnt1[A[i - 1][j]]--;

            if (cnt2[A[i - 1][j]]) update(seg2, 1, 1, n, A[i - 1][j], -1);
            ll c1 = getsum(seg1, 1, 1, n, 1, A[i][j] - 1);
            ll c2 = getsum(seg2, 1, 1, n, 1, A[i][j] - 1);
            addval(ans, c1 * DP[n - j][ov - 1] % mod * pw[n - i] % mod);
            addval(ans, (c2 - c1) * DP[n - j][ov] % mod * pw[n - i] % mod);
            if (cnt2[A[i - 1][j]]) update(seg2, 1, 1, n, A[i - 1][j], 1);
            
            ov -= cnt1[A[i][j]];
            if (cnt1[A[i][j]] && cnt2[A[i][j]]) update(seg1, 1, 1, n, A[i][j], -1);
            cnt2[A[i][j]]--;
            update(seg2, 1, 1, n, A[i][j], -1);
        }
    }
    cout << ans;
}