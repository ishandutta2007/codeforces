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

int q(int x, int y) {
    cout << "? " << x << ' ' << y << endl;
    char ret[10];
    cin >> ret;
    if (ret[0] == 'e') exit(0);
    return ret[0] == 'x' ? x : y;
}

int solve() {
    int s = 1 << 29, e = 1e9;
    if (q(0, 1) == 0) return 1;
    for (int i = 1; i < 29; i++) {
        int ret = q((1 << i) - 1, (2 << i) - 1);
        if (ret == (1 << i) - 1) {
            s = (1 << i);
            e = (2 << i) - 1;
            break;
        }
    }
    while (s < e) {
        if (e - s == 1) {
            if (q(s, e) == s) s = e;
            else e = s;
            break;
        }
        int m = ((ll)s + e) >> 1;
        if ((m & 1) == 0) m--;
        if (q(m / 2, m) == m) s = m + 1;
        else e = m;
    }
    return s;
}

int main() {
    int cnt = 0;
    while (1) {
        char start[100];
        cin >> start;
        if (start[0] != 's') break;
        int ret = solve();
        cout << "! " << ret << endl;
    }
}