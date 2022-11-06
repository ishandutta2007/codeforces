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

ll n, ans;
int k;
vector<pll> pr;
ll dp[60][60];
ll rev[61];

void solve(int it, ll mul = 1, ll pro = 1) {
    if (it == sz(pr)) {
        //cout << pro << ' ' << mul << endl;
        addval(ans, mul * pro % mod);
        return;
    }
    for (int i = 0; i <= pr[it].se; i++) {
        solve(it + 1, mul, pro * dp[i][pr[it].se] % mod);
        mul = mul * pr[it].fs % mod;
    }
}

ll pw(ll x, ll p) {
    ll r = 1;
    while (p) {
        if (p & 1) r = r * x % mod;
        x = x * x % mod;
        p >>= 1;
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(20);
    cin >> n >> k;
    for (int i = 1; i <= 60; i++) rev[i] = pw(i, mod - 2);
    for (int i = 0; i < 60; i++) {
        dp[i][i] = 1;
    }
    for (int it = 1; it <= k; it++) {
        for (int i = 1; i < 60; i++) {
            for (int j = 0; j < i; j++) {
                addval(dp[j][i], dp[j][i - 1]);
            }
        }
        for (int i = 0; i < 60; i++) {
            for (int j = 0; j <= i; j++) {
                dp[j][i] = dp[j][i] * rev[i + 1] % mod;
            }
        }
    }

    ll x = n;
    for (ll i = 2; i * i <= x; i++) {
        if (x % i != 0) continue;
        pr.emplace_back(i, 0);
        while (x % i == 0) pr.back().se++, x /= i;
    }
    if (x > 1) pr.emplace_back(x, 1); 
    solve(0);
    cout << ans;
}