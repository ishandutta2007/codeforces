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
    string s;
    cin >> s;
    while (s.size() > 0 && s.back() == '.')
        s.pop_back();
    reverse(all(s));
    while (s.size() > 0 && s.back() == '.')
        s.pop_back();
    int cnt = 0;
    for (auto to:s)
        cnt += to == '.';
    if (cnt == s.size() || cnt == 0) {
        cout << 0 << '\n';
        return;
    }
    s.pb('.');
    reverse(all(s));
    s.pb('.');
    n = s.size();
    vector<int> a;
    {
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && s[i] == s[j])
                j++;
            a.pb(j - i);
            i = j;
        }
    }
    ll ans = INFLL;
    n = a.size();
    vector<pll > pref(n + 1), suf(n + 2);
    for (int i = 2; i < n; i += 2) {
        pref[i] = {0, pref[i - 2].se + a[i - 1]};
        pref[i].fi = pref[i - 2].fi + pref[i].se * a[i];
    }
//    for (auto to:pref)
//        cout << to.fi << " ";
//    cout << '\n';
    for (int i = n - 3; i >= 0; i -= 2) {
        suf[i] = {0, suf[i + 2].se + a[i + 1]};
        suf[i].fi = suf[i + 2].fi + suf[i].se * a[i];
    }
    for (int i = 1; i < a.size(); i += 2) {
        ans = min(ans, pref[i - 1].fi + suf[i + 1].fi);
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