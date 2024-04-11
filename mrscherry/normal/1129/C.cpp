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

int m;
int S[3005];
ll dp[3005];

struct node {
    node * nxt[2];
    node() {
        nxt[0] = nxt[1] = 0;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(20);
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> S[i];
    }
    ll ans = 0;
    node * root = new node();
    for (int n = 1; n <= m; n++) {
        node * go = root;
        int t = -1;
        for (int i = n + 1; --i; ) {
            if (go->nxt[S[i]] == 0) {
                if (t == -1) t = i;
                go->nxt[S[i]] = new node();
            }
            go = go->nxt[S[i]];
        }
        dp[n + 1] = 1;
        for (int i = n + 1; --i; ) {
            dp[i] = 0;
            for (int j = i + 1; j <= i + 4 && j <= n + 1; j++) {
                if (j == i + 4) {
                    int v = 0;
                    for (int k = i; k < j; k++) {
                        v *= 2;
                        v += S[k];
                    }
                    if (v == 3 || v == 5 || v == 14 || v == 15) continue;
                }
                addval(dp[i], dp[j]);
            }
            if (i <= t) addval(ans, dp[i]);
        }
        cout << ans << '\n';
    }
}