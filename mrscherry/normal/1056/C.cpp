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
int P[2005];
int E[2005];
int U[2005];
pii es[1005];
int T;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= 2 * n; i++) {
        cin >> P[i];
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        E[a] = b;
        E[b] = a;
        es[i] = { a, b };
    }
    cin >> T;
    if (T == 1) {
        for (int i = 0; i < m; i++) {
            if (P[es[i].fs] < P[es[i].se]) swap(es[i].fs, es[i].se);
            cout << es[i].fs << endl;
            int r;
            cin >> r;
        }
        priority_queue<pii> pq;
        for (int i = 1; i <= 2 * n; i++) {
            if (E[i]) continue;
            pq.emplace(P[i], i);
        }
        while (!pq.empty()) {
            pii x = pq.top(); pq.pop();
            if (E[x.se]) continue;
            E[x.se] = 1;
            cout << x.se << endl;
            int r;
            cin >> r;
            E[r] = 1;
        }
    }
    else {
        int C = 0;
        for (int it = n; it--; ) {
            int r;
            cin >> r;
            U[r] = 1;
            if (E[r]) {
                cout << E[r] << endl;
                C++;
                U[E[r]] = 1;
            }
            else {
                for (int i = 0; i < m; i++) {
                    if (U[es[i].fs]) continue;
                    if (P[es[i].fs] < P[es[i].se]) swap(es[i].fs, es[i].se);
                    cout << es[i].fs << endl;
                    C++;
                    cin >> r;
                    U[es[i].fs] = 1;
                    U[r] = 1;
                }
                priority_queue<pii> pq;
                for (int i = 1; i <= 2 * n; i++) {
                    pq.emplace(P[i], i);
                }
                while (!pq.empty()) {
                    pii x = pq.top(); pq.pop();
                    if (U[x.se]) continue;
                    cout << x.se << endl;
                    C++;
                    if (C == n) break;
                    cin >> r;
                    U[r] = 1;
                }
                break;
            }
        }
    }
}