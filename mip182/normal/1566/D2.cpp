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
const int MAXN = 1e6 + 100;
const int INF = 1e9;
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 21;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pii > a(n * m);
    vector<int> b(n * m);
    for (int i = 0; i < n * m; i++) {
        cin >> a[i].fi;
        b[i] = a[i].fi;
        a[i].se = -i;
    }
    sort(all(a));
    ll ans = 0;
    vvb now(n, vb(m));
    vector<int> total(n);
    map<int, pii > r;
    {
        int i = 0;
        while (i < a.size()) {
            int j = i;
            while (j < a.size() && a[i].fi == a[j].fi)
                j++;
            r[a[i].fi] = {i, j - 1};
            i = j;
        }
    }
    map<int, vector<pii>> free_space;
    for (auto to: r) {
        pii range = to.se;
        int x1 = range.fi / m, y1 = range.fi % m;
        int x2 = range.se / m, y2 = range.se % m;
        vector<pii > c;
        for (int i = x1 + 1; i < x2; i++) {
            for (int j = m - 1; j >= 0; j--)
                c.pb({i, j});
        }
        free_space[to.fi] = c;
    }
    auto get_sum = [&](int x, int l, int r) {
        int s = 0;
        for (int i = l; i <= r; i++)
            s += now[x][i];
        return s;
    };
    for (int i = 0; i < n * m; i++) {
        pii range = r[b[i]];
        int x1 = range.fi / m, y1 = range.fi % m;
        int x2 = range.se / m, y2 = range.se % m;
//        cout << i << '\n';
//        for (int j = 0; j < n; j++) {
//            for (int f = 0; f < m; f++)
//                cout << now[j][f];
//            cout << '\n';
//        }
//        cout << b[i] << " " << x1 << " " << y1 << " " << x2 << " " << y2 << '\n';
        if (x1 == x2) {
            int pos = y2;
            while (now[x1][pos])
                pos--;
            now[x1][pos] = true;
            ans += get_sum(x1, 0, pos - 1);
        } else {
            int pos1 = m - 1;
            int pos2 = y2;
            while (pos1 >= y1 && now[x1][pos1])
                pos1--;
            while (pos2 >= 0 && now[x2][pos2])
                pos2--;
            if (pos1 >= y1) {
                now[x1][pos1] = true;
                ans += get_sum(x1, 0, pos1 - 1);
            } else if (!free_space[b[i]].empty()) {
                free_space[b[i]].pop_back();
            } else {
                now[x2][pos2]=true;
            }
        }
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