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

int n; ll s;

bool ok(int x) {
    ll sum = 0, mx = 1;
    int num = 0, i = 1;
    while (1) {
        if (num + mx >= n) {
            sum += (ll)(n - num) * i;
            break;
        }
        sum += mx * i;
        num += mx;
        i++;
        mx *= x;
    }
    return sum <= s;
}

int H[100005];
ll M[100005];
int CNT[100005];
vector<int> Hs[100005];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(20);
    cin >> n >> s;
    if (s < 2 * n - 1 || n * (n + 1ll) / 2ll < s) {
        cout << "No";
        return 0;
    }
    cout << "Yes" << endl;
    int st = 1, ed = n - 1;
    while (st < ed) {
        int md = st + ed >> 1;
        if (ok(md)) ed = md;
        else st = md + 1;
    }
    H[1] = M[1] = 1;
    for (int i = 2; i <= n; i++) H[i] = 1, M[i] = min(M[i - 1] * st, (ll)n);
    ll sum = n * (n + 1ll) / 2ll;
    int hm = 2, hl = n;
    while (sum > s) {
        while (hm <= n && H[hm] >= M[hm]) hm++;
        ll sm = hl - hm;
        if (sum - s <= sm) {
            H[hl]--;
            H[hl - (sum - s)]++;
            sum = s;
        }
        else {
            int st = 1, ed = H[hl];
            while (st < ed) {
                int md = st + ed + 1 >> 1;
                if (sm * md <= sum - s) st = md;
                else ed = md - 1;
            }
            H[hl] -= st;
            H[hm] += st;
            sum -= sm * st;
        }
        if (H[hl] == 0) hl--;
    }
    Hs[1].pp(1);
    int P = 1;
    for (int i = 2; H[i]; i++) {
        for (int j = 0; j < H[i]; j++) {
            P++;
            while (CNT[Hs[i - 1].back()] >= st) Hs[i - 1].pop_back();
            cout << Hs[i - 1].back() << ' ';
            CNT[Hs[i - 1].back()]++;
            Hs[i].pp(P);
        }
    }
}