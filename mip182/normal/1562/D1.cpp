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
    for (auto &i: v) --i;
    return v;
}

template<typename T>
vector<T> &operator++(vector<T> &v) {
    for (auto &i: v) ++i;
    return v;
}

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for (auto &i: v) is >> i;
    return is;
}

template<typename T>
ostream &operator<<(ostream &os, vector<T> v) {
    for (auto &i: v) os << i << ' ';
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
const int MAXN = 3e5 + 100;
const ll INF = 1e9;
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 21;
int t[4 * MAXN];
string a;

void build(int v, int vl, int vr) {
    if (vl == vr) {
        if (a[vl] == '+')
            t[v] = 1;
        else
            t[v] = -1;
        if (vl % 2 == 1)
            t[v] *= -1;
        return;
    }
    int mid = ((vl + vr) >> 1);
    build(2 * v + 1, vl, mid);
    build(2 * v + 2, mid + 1, vr);
    t[v] = t[2 * v + 1] + t[2 * v + 2];
}

int query(int v, int vl, int vr, int l, int r) {
    if (vl > r || vr < l)
        return 0;
    if (l <= vl && vr <= r)
        return t[v];
    int mid = ((vl + vr) >> 1);
    return query(2 * v + 1, vl, mid, l, r) + query(2 * v + 2, mid + 1, vr, l, r);
}

void solve() {
    int n, q;
    cin >> n >> q;
    cin >> a;
    build(0, 0, n-1);
    // a+b becomes a-b+-1 = 0
    // a=b+-1
    // if odd
    // a-b+a[i]=0
    // else
    // a-b-a[i]=0
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        int x = query(  0, 0, n - 1, l, r);
//        cout<<"x "<<x.fi<<'\n';
        if (x == 0) {
            cout << 0 << '\n';
        } else {
            if (abs(x) % 2 == 1)
                cout << 1 << '\n';
            else
                cout << 2 << '\n';
        }
    }
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