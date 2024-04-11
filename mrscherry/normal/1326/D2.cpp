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

pii max(pii a, pii b) {
    if (a.fs - a.se < b.fs - b.se) return b;
    return a;
}

char S[1000005], T[2000005];
int A[2000005], L[2000005], R[2000005];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(20);
    int t;
    cin >> t;
    while (t--) {
        cin >> S + 1;
        int n = strlen(S + 1);
        int m = 2 * n + 1;
        for (int i = 1; i <= m; i++) {
            if (i % 2) T[i] = '.';
            else T[i] = S[i / 2];
        }
        T[m + 1] = 0;
        int r = 0, p = 0;
        for (int i = 1; i <= m; i++) {
            if (i <= r) A[i] = min(A[2 * p - i], r - i);
            else A[i] = 0;
            while (i - A[i] - 1 > 0 && i + A[i] + 1 <= m && T[i - A[i] - 1] == T[i + A[i] + 1]) A[i]++;
            if (r < i + A[i]) r = i + A[i], p = i;
        }
        for (int i = 1; i <= m; i++) {
            L[i] = R[i] = 0;
        }
        for (int i = 1; i <= m; i++) {
            if (i >= n + 1) setmax(R[i + A[i]], 2 * A[i] + 1);
            if (i <= n + 1) setmax(L[i - A[i]], 2 * A[i] + 1);
        }
        for (int i = 2; i <= n + 1; i++) {
            setmax(L[i], L[i - 1] - 2);
        }
        for (int i = m - 1; i >= n + 1; i--) {
            setmax(R[i], R[i + 1] - 2);
        }
        pii ans = pii(1, n);
        for (int i = 0; 2 * i <= n; i++) {
            if (i && S[i] != S[n - i + 1]) break;
            ans = max(ans, pii(i + 1 + (L[2 * (i + 1)] + 1) / 2, n - i));
            ans = max(ans, pii(i + 1, n - i - (R[2 * (n - i)] + 1) / 2));
        }
        for (int i = 1; i < ans.fs; i++) {
            cout << S[i];
        }
        for (int i = ans.se + 1; i <= n; i++) {
            cout << S[i];
        }
        cout << '\n';
    }
}