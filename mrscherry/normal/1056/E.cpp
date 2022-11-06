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

int n, m;
ll P;
char S[100005];
char T[1000005];
ll RK[1000005];

ll pw(ll x, ll p) {
    ll ans = 1;
    while (p) {
        if (p & 1) ans *= x, ans %= mod;
        x *= x; x %= mod;
        p >>= 1;
    }
    return ans;
}

ll getStr(int s, int e) {
    return (RK[e] + mod - RK[s - 1] * pw(P, e - s + 1) % mod) % mod;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> S + 1 >> T + 1;
    n = strlen(S + 1);
    m = strlen(T + 1);
    P = randomLong(20, 1000);
    for (int i = 1; i <= m; i++) {
        RK[i] = RK[i - 1] * P + T[i];
        RK[i] %= mod;
    }
    int C[2] = {};
    for (int i = 1; i <= n; i++) {
        C[S[i] -= '0']++;
    }
    int ans = 0;
    for (int L = 1; L * C[0] < m; L++) {
        int cnt = 1;
        if ((m - L * C[0]) % C[1] != 0) continue;
        int R = (m - L * C[0]) / C[1];
        ll R0 = -1, R1 = -1;
        int ST = 1;
        for (int i = 1; i <= n; i++) {
            if (S[i] == 0) {
                if (R0 != -1) {
                    if (R0 != getStr(ST, ST + L - 1)) cnt = 0;
                }
                else R0 = getStr(ST, ST + L - 1);
                ST += L;
            }
            else {
                if (R1 != -1) {
                    if (R1 != getStr(ST, ST + R - 1)) cnt = 0;
                }
                else R1 = getStr(ST, ST + R - 1);
                ST += R;
            }
        }
        if (L == R && R0 == R1) cnt = 0;
        ans += cnt;
    }
    cout << ans;
}