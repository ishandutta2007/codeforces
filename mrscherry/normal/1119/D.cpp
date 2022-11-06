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

int n, q;
ll S[100005];
pll qs[100005];
ll ans[100005];
ll L[100005];
ll R[100005];
int par[100005];
int find(int x) {
    if (par[x] != x) return par[x] = find(par[x]);
    return x;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(20);
    cin >> n;
    vector<pll> ord;
    for (int i = 1; i <= n; i++) {
        cin >> S[i];
    }
    sort(S + 1, S + n + 1);
    n = unique(S + 1, S + n + 1) - S - 1;
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        L[i] = R[i] = S[i];
        if (i > 1) {
            ord.emplace_back(L[i] - R[i - 1] - 1, i);
        }
    }
    vsort(ord);
    cin >> q;
    for (int i = 1; i <= q; i++) {
        ll L, R;
        cin >> L >> R;
        qs[i] = pll(R - L, i);
    }
    sort(qs + 1, qs + q + 1);
    ll sum = 0;
    int cnt = n;
    for (int i = 1, j = 0; i <= q; i++) {
        while (j < sz(ord) && ord[j].fs <= qs[i].fs) {
            int it = ord[j].se - 1;
            int jt = ord[j].se;
            it = find(it);
            jt = find(jt);
            sum += L[jt] - R[it] - 1;
            cnt--;
            par[it] = jt;
            L[jt] = L[it];
            j++;
        }
        ans[qs[i].se] = n + sum + cnt * qs[i].fs;
    }
    for (int i = 1; i <= q; i++) {
        cout << ans[i] << ' ';
    }
}