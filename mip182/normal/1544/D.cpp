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
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define MANX MAXN
#define itn int
#define dbg(x); {cout << #x << "=" << x << ", ";}
#define in(x); { for (auto &to : x) cin >> to;}
#define out(x); { for (auto &to : x) cout << to << " "; cout << '\n'; }

template<class T>
bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }

template<class T>
bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const ll INFLL = 1e18;
const int MAXN = 1e6 + 100;
const ll INF = 1e9;
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 21;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);in(a);
    for (auto &to:a)
        to--;
    vector<int> ans(n, -1);
    vector<int> chose(n, -1);
    for (int i = 0; i < n; i++) {
        if (chose[a[i]] == -1)
            ans[i] = a[i], chose[a[i]] = i;
        else {
        }
    }
    vector<int> b;
    for (int i = 0; i < n; i++) {
        if (chose[i] == -1 && ans[i] == -1)
            b.pb(i);
    }
//    cout << "B\n";
//    cout << b.size() << '\n';
//    cout<<b[0]<<'\n';
    while (b.size() >= 2) {
        int x = b.back();
        b.pop_back();
        int y = b.back();
        b.pop_back();
        ans[x] = y;
        ans[y] = x;
        chose[x] = y;
        chose[y] = x;
    }
    if (!b.empty()) {
        int x = b[0];
        int y = a[x];
        int f = chose[y];
//        cout << x << " " << y << " " << f << '\n';
        ans[f] = x;
        ans[x] = y;
        chose[x] = f;
        chose[y] = x;
    }
    vector<int> free, bad;
    for (int i = 0; i < n; i++) {
        if (chose[i] == -1)
            free.pb(i);
        if (ans[i] == -1)
            bad.pb(i);
    }
    for (int i = 0; i < free.size(); i++)
        ans[bad[i]] = free[i];
//    set<int> cant;
//    vector<vi > cnt(n);
//    for (int i = 0; i < n; i++) {
//        cnt[a[i]].pb(i);
//    }
//    vector<int> ans(n, -1);
//    vector<int> free, bad;
//    for (int i = 0; i < n; i++) {
//        if (cnt[i].size() <= 1)
//            continue;
//        int ok = -1;
//        for (auto to:cnt[i]) {
//            if (cnt[to].size() == 0) {
//                if (ok == -1) {
//                    ok = to;
//                    ans[to] = i;
//                }
//            }
//        }
//        if (ok == -1) {
//            for (int j = 1; j < cnt[i].size(); j++)
//                free.pb(cnt[i][j]);
//        } else {
//            for (auto to:cnt[i]) {
//                if (to == ok)
//                    continue;
//                if (cnt[to].size() == 0)
//                    bad.pb(to);
//                else
//                    free.pb(to);
//            }
//        }
//    }
//    assert(free.size() <= bad.size());
//    for (int i = 0; i < free.size(); i++) {
//        ans[free[i]] = bad[i];
//    }
//    for (int i = free.size(); i + 1 < bad.size(); i += 2) {
//
//    }
//    while (bad.size() >= 2) {
//        int x = bad.back();
//        bad.pop_back();
//        int y = bad.back();
//        bad.pop_back();
//        ans[x] = y;
//        ans[y] = x;
//    }
//    for (int i = 0; i < n; i++) {
//        if (ans[i] == -1)
//            ans[i] = a[i];
//    }
    int anss = 0;
    for (int i = 0; i < n; i++)
        anss += ans[i] == a[i];
    cout << anss << '\n';
    for (auto to:ans)
        cout << to + 1 << " ";
    cout << '\n';
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