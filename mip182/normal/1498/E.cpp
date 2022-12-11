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
        to = n - 1 - to;
    vector<pii > b(n);
    for (int i = 0; i < n; i++)
        b[i] = {a[i], i};
    sort(all(b));
    int st = 0;
    while (st < n && b[st].fi == 0) {
        for (int i = st + 1; i < n; i++)
            b[i].fi--;
        st++;
    }
    if (st == n) {
        cout << "! 0 0" << endl;
        return;
    }
    int total = n - st;
    int en = n - 1;
    while (en >= st && b[en].fi == total - 1) {
        total--;
        en--;
    }
    if (en < st) {
        cout << "! 0 0" << endl;
        return;
    }
    vector<pair<int, pii>> ask;
    for (int i = st; i <= en; i++) {
        for (int j = i + 1; j <= en; j++)
            ask.pb({abs(b[i].fi - b[j].fi), {-i, -j}});
    }
    sort(rall(ask));
    for (auto to:ask) {
        cout << "? " << b[-to.se.fi].se + 1 << " " << b[-to.se.se].se + 1 << endl;
        string s;
        cin >> s;
        if (s[0] == 'Y') {
            cout << "! " << b[-to.se.fi].se + 1 << " " << b[-to.se.se].se + 1 << endl;
            return;
        }
    }
    cout << "! 0 0" << endl;
}

int main() {
#ifdef Mip182
//    freopen("a.in", "r", stdin);
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