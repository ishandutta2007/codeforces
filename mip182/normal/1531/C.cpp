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

string f(int n, char s) {
    string ss;
    for (int i = 0; i < n; i++)
        ss += s;
    return ss;
}

void solve() {
    int n;
    cin >> n;
    int now_sq = INF;
    pair<int, int> mx;
    for (int now = 1; now * now <= n; now++) {
        int s = now * now;
        if ((n - s) & 1)
            continue;
        int cnt = 0;
        while (s < n)
            s += 2 * now, cnt++;
        if (now_sq > now + cnt) {
            now_sq = now + cnt;
            mx = {now, cnt};
        }
    }
    if (now_sq == INF)
        cout << -1 << '\n';
    else {
        cout << now_sq << '\n';
        int s = mx.fi * mx.fi + mx.fi * 2 * (mx.se - 1);
        int sz_ha = (n - s) / 2;
        if (mx.fi * mx.fi == n) {
            for (int i = 0; i < mx.fi; i++)
                cout << f(mx.fi, 'o') << '\n';
            return;
        }
        cout << f(sz_ha, 'o') + f(now_sq - sz_ha, '.') << '\n';
        for (int i = 0; i < mx.se - 1; i++)
            cout << f(mx.fi, 'o') + f(now_sq - mx.fi, '.') << '\n';
        for (int i = 0; i < mx.fi - sz_ha; i++)
            cout << f(mx.fi + mx.se - 1, 'o') + f(now_sq - mx.fi - mx.se + 1, '.') << '\n';
        for (int i = 0; i < sz_ha; i++)
            cout << f(mx.fi + mx.se, 'o') + f(now_sq - mx.fi - mx.se, '.') << '\n';
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
//    cin>>_t;
    while (_t--)
        solve();
#ifdef Mip182
    cout << '\n' << "Time : " << (double) (clock()) / CLOCKS_PER_SEC << '\n';
#endif
}