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

int n, q;
bitset<7005> S[100005], di[7005];
int ch[7005];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(20);
    for (int i = 1; i <= 7000; i++) {
        for (int j = 1; i * j <= 7000; j++) {
            int pos = 1;
            for (int k = 2; k * k <= j; k++) {
                if (j % (k * k) == 0) {
                    pos = 0;
                    break;
                }
            }
            if (pos) di[i][i * j] = 1;
        }
    }
    cin >> n >> q;
    while (q--) {
        int T;
        cin >> T;
        if (T == 1) {
            int x, v;
            cin >> x >> v;
            S[x].reset();
            for (int i = 1; i * i <= v; i++) {
                if (v % i != 0) continue;
                S[x][i] = 1;
                S[x][v / i] = 1;
            }
        }
        else if (T == 2 || T == 3) {
            int x, y, z;
            cin >> x >> y >> z;
            if (T == 2) S[x] = S[y] ^ S[z];
            else S[x] = S[y] & S[z];
        }
        else if (T == 4) {
            int x, v;
            cin >> x >> v;
            cout << (S[x] & di[v]).count() % 2;
        }
    }
}