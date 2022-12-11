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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ans = 0;
    int l = 1, r = n / k;
    vector<vector<int>> pref(n + 1, vi(k + 1));
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1];
        if (s[i - 1] == '?')
            pref[i][k]++;
        else
            pref[i][s[i - 1] - 'a']++;
    }
    auto can = [&](int pos, int mid, int i) {
        if (pos + mid - 1 <= n) {
            return (pref[pos + mid - 1][k] + pref[pos + mid - 1][i] - (pref[pos - 1][k] + pref[pos - 1][i])) == mid;
        } else
            return false;
    };
    while (l <= r) {
        int mid = ((l + r) >> 1);
        vector<vector<int>> nxt(n + 1, vi(k, n + 1));
        for (int i = n - 1; i >= 0; i--) {
            nxt[i] = nxt[i + 1];
            for (int j = 0; j < k; j++) {
                if (can(i + 1, mid, j))
                    nxt[i][j] = i + mid;
            }
        }
//        for (auto to:nxt[1])
//            cout << to << " ";
//        cout << '\n';
        vector<int> dp((1 << k), INF);
        dp[0] = 0;
        for (int mask = 0; mask < (1 << k); mask++) {
            if (dp[mask] == INF)
                continue;
            for (int i = 0; i < k; i++) {
                if ((mask >> i) & 1)
                    continue;
                if (nxt[dp[mask]][i] <= n)
                    uin(dp[mask | (1 << i)], nxt[dp[mask]][i]);
            }
        }
//        for (auto to:dp)
//            cout << to << " ";
//        cout << '\n';
        if (dp[(1 << k) - 1] == INF)
            r = mid - 1;
        else
            l = mid + 1, ans = mid;
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
//    cin>>_t;
    while (_t--)
        solve();
#ifdef Mip182
    cout << '\n' << "Time : " << (double) (clock()) / CLOCKS_PER_SEC << '\n';
#endif
}