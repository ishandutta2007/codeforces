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

void no() {
    cout << -1;
    exit(0);
}

int n;
vector<int> E[100005];
int S[100005];
int mn[100005];

void dfs1(int x) {
    mn[x] = mod;
    for (int i : E[x]) {
        dfs1(i);
        mn[x] = min(mn[x], mn[i]);
        if (S[i] != -1) mn[x] = min(mn[x], S[i]);
    }
    if (mn[x] < S[x]) no();
}

ll dfs2(int x, ll sum = 0) {
    ll ret = 0;
    if (S[x] != -1) {
        ret = S[x] - sum;
        sum = S[x];
        for (int i : E[x]) {
            ret += dfs2(i, sum);
        }
    }
    else {
        if (mn[x] != mod) ret = mn[x] - sum, sum = mn[x];
        else return 0;
        for (int i : E[x]) {
            ret += dfs2(i, sum);
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(20);
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        E[p].pp(i);
    }
    for (int i = 1; i <= n; i++) cin >> S[i];
    dfs1(1);
    cout << dfs2(1);
}