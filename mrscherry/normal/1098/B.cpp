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

int n, m;
vector<vector<int>> C;
char str[300005];
int tr[305];
char ch[10];

int diff = mod;
vector<vector<int>> R;
vector<vector<int>> ans;

void solveS(int i = 0, int j = 0, int d = 0) {
    if (diff <= d) return;
    if (j == m) {
        solveS(i + 1, 0, d);
        return;
    }
    if (i == n) {
        ans = R;
        diff = d;
        return;
    }
    for (int it = 0; it < 4; it++) {
        R[i][j] = it;
        bool pos = true;
        for (int x = i - 1; x <= i + 1; x++) {
            for (int y = j - 1; y <= j + 1; y++) {
                if (x < 0 || x >= n || y < 0 || y >= m || (x == i && y == j)) continue;
                if (R[i][j] == R[x][y]) {
                    pos = false;
                    break;
                }
            }
            if (!pos) break;
        }
        if (pos) solveS(i, j + 1, d + (R[i][j] != C[i][j]));
    }
    R[i][j] = -1;
}

void solve1(int As, int Bs, int Cs, int Ds) {
    int d = 0;
    for (int i = 0; i < n; i++) {
        int D1 = 0, D2 = 0;
        int ar[2];
        if (i % 2) ar[0] = As, ar[1] = Bs;
        else ar[0] = Cs, ar[1] = Ds;
        for (int j = 0; j < m; j++) {
            if (ar[j % 2] != C[i][j]) D1++;
            if (ar[1 - j % 2] != C[i][j]) D2++;
        }
        d += min(D1, D2);
        for (int j = 0; j < m; j++) {
            if (D1 < D2) R[i][j] = ar[j % 2];
            else R[i][j] = ar[1 - j % 2];
        }
    }
    if (d < diff) ans = R, diff = d;
}

void solve2(int As, int Bs, int Cs, int Ds) {
    int d = 0;
    for (int i = 0; i < m; i++) {
        int D1 = 0, D2 = 0;
        int ar[2];
        if (i % 2) ar[0] = As, ar[1] = Bs;
        else ar[0] = Cs, ar[1] = Ds;
        for (int j = 0; j < n; j++) {
            if (ar[j % 2] != C[j][i]) D1++;
            if (ar[1 - j % 2] != C[j][i]) D2++;
        }
        d += min(D1, D2);
        for (int j = 0; j < n; j++) {
            if (D1 < D2) R[j][i] = ar[j % 2];
            else R[j][i] = ar[1 - j % 2];
        }
    }
    if (d < diff) ans = R, diff = d;
}

void solve3(int As, int Bs, int Cs, int Ds) {
    int ar[2][2] = { As, Bs, Cs, Ds };
    int d = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (C[i][j] != ar[i % 2][j % 2]) d++;
            R[i][j] = ar[i % 2][j % 2];
        }
    }
    if (d < diff) ans = R, diff = d;
}

void solveB() {
    vector<int> v = { 0, 1, 2, 3 };
    while (1) {
        //cout << v[0] << v[1] << v[2] << v[3] << endl;
        solve1(v[0], v[1], v[2], v[3]);
        solve2(v[0], v[1], v[2], v[3]);
        solve3(v[0], v[1], v[2], v[3]);
        next_permutation(all(v));
        if (v == vector<int>({ 0, 1, 2, 3 })) break;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(20);
    ch[tr['A'] = 0] = 'A';
    ch[tr['G'] = 1] = 'G';
    ch[tr['C'] = 2] = 'C';
    ch[tr['T'] = 3] = 'T';
    cin >> n >> m;
    C.resize(n, vector<int>(m));
    R.resize(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++) {
        cin >> str;
        for (int j = 0; j < m; j++) {
            C[i][j] = tr[str[j]];
        }
    }
    if (n * m <= 9) solveS(); else
    solveB();
    //cout << diff << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ch[ans[i][j]];
        }
        cout << '\n';
    }
}