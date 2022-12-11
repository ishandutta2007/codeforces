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
const int MAXN = 1e5 + 100;
const int INF = 1e9;
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 21;
int f[MAXN];
int C;

void add( int x,int pos) {
    for (; pos < C; pos |= pos + 1)
        f[pos] += x;
}

int res(int l) {
    int sum = 0;
    for (; l >= 0; l = ((l + 1) & l) - 1)
        sum += f[l];
    return sum;
}

int res(int l, int r) {
    return res(r) - res(l - 1);
}

void solve() {
    int n;
    cin >> n;
    C = n + 2;
    for (int i = 0; i < C; i++)
        f[i] = 0;
    string s, t;
    cin >> s >> t;
    vector<deque<int>> pos(26);
    for (int i = 0; i < n; i++) {
        pos[s[i] - 'a'].pb(i);
    }
    ll ans = INFLL;
    ll total = 0;
    for (int cur = 0; cur < n; cur++) {
//        cout << "CUR = " << cur << ", TOTAL = " << total << '\n';
        for (int less = 0; less < t[cur] - 'a'; less++) {
            if (pos[less].empty())
                continue;
            int p = pos[less].front();
            int cnt = p - cur;
            cnt += res(p, n - 1);
            uin(ans, cnt + total);
        }
        int now = t[cur] - 'a';
        if (pos[now].empty())
            break;
        int cnt = pos[now].front() - cur;
//        cout << pos[now].front() << " " << res(pos[now].front(), n - 1) << '\n';
        cnt += res(pos[now].front(), n - 1);
//        cout << "adding" << pos[now].front() << '\n';
        add(1, pos[now].front());
        pos[now].pop_front();
        total += cnt;
    }
    cout << (ans == INFLL ? -1 : ans) << '\n';
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