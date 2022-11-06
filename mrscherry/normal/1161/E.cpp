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

string Q(const vector<pii> &v) {
    if (v.empty()) return "";
    cout << "Q " << sz(v);
    for (pii i : v) {
        cout << ' ' << i.fs;
        cout << ' ' << i.se;
    }
    cout << endl;
    string s;
    cin >> s;
    if (s == "-1") exit(0);
    return s;
}

int n;
int C[100005];
int B[100005];
int U[100005];
int S[100005];
void pro() {
    vector<pii> q;
    for (int i = 2; i <= n; i += 2) {
        q.ep(i - 1, i);
    }
    string s1 = Q(q);
    q.clear();
    for (int i = 3; i <= n; i += 2) {
        q.ep(i - 1, i);
    }
    string s2 = Q(q);
    q.clear();
    for (int i = 0; i < sz(s1); i++) {
        B[i * 2 + 2] = '1' - s1[i];
    }
    for (int i = 0; i < sz(s2); i++) {
        B[i * 2 + 3] = '1' - s2[i];
    }
    vector<pii> need;
    for (int i = 2, j = 3; i <= n; i++) {
        if (!B[i]) continue;
        j = max(i + 1, j);
        while (j <= n && !B[j]) j++;
        if (j > n) break;
        need.ep(i, j);
    }
    while (sz(need)) {
        vector<pii> next, q;
        int j = 0;
        for (int i = 1; i <= n; i++) {
            U[i] = 0;
        }
        for (pii i : need) {
            if (U[i.fs - 1] == 0 && U[i.se] == 0) {
                U[i.fs - 1] = U[i.se] = 1;
                i.fs--;
                q.pp(i);
            }
            else {
                next.pp(i);
            }
        }
        string s = Q(q);
        for (int i = 0; i < sz(s); i++) {
            S[q[i].fs + 1] = s[i] - '0';
        }
        need = next;
    }
    for (int i = 2, j = 3; i <= n; i++) {
        if (!B[i]) continue;
        j = max(i + 1, j);
        while (j <= n && !B[j]) j++;
        if (j > n) break;
        B[j] = B[i] ^ (S[i] * 3);
    }
    B[1] = 0;
    for (int i = 2; i <= n; i++) B[i] += B[i - 1], B[i] %= 3;
    int k[3] = {};
    for (int i = 1; i <= n; i++) {
        k[B[i]]++;
    }
    cout << "A " << k[0] << ' ' << k[1] << ' ' << k[2] << '\n';
    for (int i = 0; i < 3; i++) {
        for (int j = 1; j <= n; j++) {
            if (B[j] == i) cout << j << ' ';
        }
        cout << '\n';
    }
    cout.flush();
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(20);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> n;
        if (n == -1) break;
        pro();
    }
}