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

int n;
int k[1000005];
int p[5005];
vector<pii> c[5005];
int kc[5005];
int xc[5005];
int sm[5005];
ll dep[5005];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(20);
    for (int i = 2; i <= 5000; i++) {
        if (p[i] ^= 1) {
            for (int j = i * i; j <= 5000; j += i) {
                p[j] = 1;
            }
        }
    }
    for (int i = 0; i <= 5000; i++) {
        for (int j = 2; j <= i; j++) {
            if (!p[j]) continue;
            int cnt = 0;
            for (int x = j; x <= i; x *= j) {
                cnt += i / x;
            }
            c[i].emplace_back(j, cnt);
            dep[i] += cnt;
        }
    }
    cin >> n;
    vector<int> remain;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
        kc[k[i]]++;
        remain.push_back(k[i]);
        if (k[i] > 1) sm[c[k[i]].back().fs]++;
        ans += dep[k[i]];
    }
    sort(remain.begin(), remain.end());
    remain.erase(unique(remain.begin(), remain.end()), remain.end());
    while (1) {
        int nxt = 0;
        for (int i = 2; i <= 5000; i++) {
            if (!p[i]) continue;
            if (n / 2 < sm[i]) {
                nxt = i;
                break;
            }
        }
        if (!nxt) break;
        vector<int> nremain;
        int mn = 1e9;
        for (int i : remain) {
            if (c[i].empty()) continue;
            if (c[i].back().fs != nxt) {
                sm[c[i].back().fs] -= kc[i];
                continue;
            }
            mn = min(mn, c[i].back().se);
            nremain.push_back(i);
        }
        ans -= (ll)mn * sm[nxt];
        ans += (ll)mn * (n - sm[nxt]);
        remain = nremain;
        for (int i : remain) {
            c[i].back().se -= mn;
            if (c[i].back().se) continue;
            sm[nxt] -= kc[i];
            c[i].pop_back();
            if (c[i].empty()) continue;
            sm[c[i].back().fs] += kc[i];
        }
    }
    cout << ans;
}