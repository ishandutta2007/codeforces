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

int F[100005][5];

struct node {
    int C[2][2];
    void init(int x) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                if (F[x][i] || F[x][j]) C[i][j] = 0;
                else C[i][j] = 1;
            }
        }
    }
    node operator+(const node &p) const {
        node ret;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                ret.C[i][j] = 0;
            }
        }
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    if (C[i][j] && p.C[j][k]) ret.C[i][k] = 1;
                }
            }
        }
        return ret;
    }
} seg[400005];

void init(int i, int s, int e) {
    if (s == e) {
        seg[i].init(s);
        return;
    }
    int m = s + e >> 1;
    init(i * 2, s, m);
    init(i * 2 + 1, m + 1, e);
    seg[i] = seg[i * 2] + seg[i * 2 + 1];
}

void update(int i, int s, int e, int x) {
    if (s == e) {
        seg[i].init(x);
        return;
    }
    int m = s + e >> 1;
    if (x <= m) update(i * 2, s, m, x);
    else update(i * 2 + 1, m + 1, e, x);
    seg[i] = seg[i * 2] + seg[i * 2 + 1];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(20);
    int n, q;
    cin >> n >> q;
    init(1, 1, n);
    for (int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;
        F[y][x - 1] ^= 1;
        update(1, 1, n, y);
        cout << (seg[1].C[0][1] ? "Yes\n" : "No\n");
    }
}