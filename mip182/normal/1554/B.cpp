#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vd vector <double>
#define vll vector <ll>
#define fi first
#define se second
#define si set <int>
#define sll set <ll>
#define spii set <pii>
#define vs vector <string>
#define vpii vector <pair <int, int> >
#define vpll vector <pair <long long, long long> >
#define vvi vector <vector <int> >
#define vvpii vector <vector <pii > >
#define vb vector <bool>
#define vvb vector <vb>
#define mp make_pair
#define vvll vector <vll>
#define vsi vector <si>
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define MANX MAXN
#define itn int
#define dbg(x); {cout << #x << "=" << x << ", ";}

template<class T>
bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }

template<class T>
bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

template<typename T>
vector<T> &operator--(vector<T> &v) {
    for (auto &i : v) --i;
    return v;
}

template<typename T>
vector<T> &operator++(vector<T> &v) {
    for (auto &i : v) ++i;
    return v;
}

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for (auto &i : v) is >> i;
    return is;
}

template<typename T>
ostream &operator<<(ostream &os, vector<T> v) {
    for (auto &i : v) os << i << ' ';
    return os;
}

template<typename T, typename U>
pair<T, U> &operator--(pair<T, U> &p) {
    --p.first;
    --p.second;
    return p;
}

template<typename T, typename U>
pair<T, U> &operator++(pair<T, U> &p) {
    ++p.first;
    ++p.second;
    return p;
}

template<typename T, typename U>
istream &operator>>(istream &is, pair<T, U> &p) {
    is >> p.first >> p.second;
    return is;
}

template<typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> p) {
    os << p.first << ' ' << p.second;
    return os;
}

template<typename T, typename U>
pair<T, U> operator-(pair<T, U> a, pair<T, U> b) { return mp(a.first - b.first, a.second - b.second); }

template<typename T, typename U>
pair<T, U> operator+(pair<T, U> a, pair<T, U> b) { return mp(a.first + b.first, a.second + b.second); }

const ll INFLL = 1e18;
const int MAXN = 1e6 + 100;
const ll INF = 1e9;
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 21;

void solve() {
    int n, k;
    cin >> n >> k;
    int x = 1;
    int cnt = 0;
    while (x <= n)
        x <<= 1, cnt++;
    vector<pii > a(x, {-1, -1});
    for (int i = 1; i <= n; i++) {
        int y;
        cin >> y;
        if (a[y].fi == -1)
            a[y].fi = i;
        else {
            swap(a[y].fi, a[y].se);
            a[y].fi = i;
        }
    }
    ll ans = -INFLL;
    vector<pii > b = a;
    for (int i = 0; i < cnt; i++) {
        for (int mask = 0; mask < x; mask++) {
            if ((mask >> i) & 1) {
                set<int> s = {b[mask].fi, b[mask].se, b[mask ^ (1 << i)].fi, b[mask ^ (1 << i)].se};
                while (s.size() > 2)
                    s.erase(s.begin());
                b[mask] = {-1, -1};
                while (!s.empty()) {
                    int y = *s.begin();
                    s.erase(y);
                    if (b[mask].fi > y) {
                        b[mask].se = y;
                    } else
                        swap(b[mask].fi, b[mask].se), b[mask].fi = y;
                }
            }
        }
    }
    for (int mask = 0; mask < x; mask++) {
        if (b[mask].se == -1)
            continue;
//        cout << mask << '\n';
//        cout << b[mask].fi << " " << b[mask].se << " " << 1ll * b[mask].fi * b[mask].se * -1ll * k * mask << '\n';
        uax(ans, 1ll * b[mask].fi * b[mask].se - 1ll * k * mask);
    }
    cout << ans << '\n';
}

int main() {
#ifdef Mip182
    freopen("a.in", "r", stdin);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int _t;
    _t = 1;
    cin >> _t;
    while (_t--)
        solve();
#ifdef Mip182
    cout << '\n' << "Time : " << (double) (clock()) / CLOCKS_PER_SEC << '\n';
#endif
}