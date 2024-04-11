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
    int n, cnt_l, cnt_r;
    cin >> n >> cnt_l >> cnt_r;
    vector<int> l(n), r(n);
    int ans = 0;
    for (int i = 0; i < cnt_l; i++) {
        int x;
        cin >> x;
        x--;
        l[x]++;
    }
    for (int i = 0; i < cnt_r; i++) {
        int x;
        cin >> x;
        x--;
        r[x]++;
    }
    vector<int> le_even, le_odd, ri_even, ri_odd;
    for (int i = 0; i < n; i++) {
        int x = min(l[i], r[i]);
        l[i] -= x;
        r[i] -= x;
        if (l[i] == 0 && r[i] == 0)
            continue;
        if (l[i]) {
            if (l[i] & 1)
                le_odd.pb(l[i]);
            else
                le_even.pb(l[i]);
        } else {
            if (r[i] & 1)
                ri_odd.pb(r[i]);
            else
                ri_even.pb(r[i]);
        }
    }
    while (!le_odd.empty() && !ri_odd.empty()) {
        int x = le_odd.back();
        int y = ri_odd.back();
        le_odd.pop_back();
        ri_odd.pop_back();
        ans++;
        if (x > 1)
            le_even.pb(x - 1);
        if (y > 1)
            ri_even.pb(y - 1);
    }
    if (le_odd.size() < ri_odd.size())
        swap(le_odd, ri_odd), swap(le_even, ri_even);
    while (le_odd.size() >= 2 && !ri_even.empty()) {
        int x = le_odd.back();
        le_odd.pop_back();
        int y = le_odd.back();
        le_odd.pop_back();
        int f = ri_even.back();
        ri_even.pop_back();
        x--;
        y--;
        f -= 2;
        ans += 2;
        if (x)
            le_even.pb(x);
        if (y)
            le_even.pb(y);
        if (f)
            ri_even.pb(f);
    }
    for (auto to:le_odd)
        ans += (to + 1) / 2;
    for (auto to:le_even)
        ans += (to + 1) / 2;
    for (auto to:ri_even)
        ans += (to + 1) / 2;
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