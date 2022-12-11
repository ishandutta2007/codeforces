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
int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 21;

int add(int a, int b) {
    a += b;
    if (a >= mod1)
        return a - mod1;
    return a;
}

int sub(int a, int b) {
    a -= b;
    if (a < 0)
        return a + mod1;
    return a;
}

void ad(int &x, int y) {
    x = add(x, y);
}

int mult(int a, int b) {
    return 1ll * a * b % mod1;
}

int A(int n, int b) {
    int ans = 1;
    for (int i = n; i > b; i--)
        ans = mult(ans, i);
    return ans;
}

void solve() {
    int n;
    cin >> n >> mod1;
    vector<vector<int>> num_per(n + 1);
    vector<vector<int>> pref(n + 1);
    num_per[1] = vi(1, 1);
    for (int i = 2; i <= n; i++) {
        num_per[i] = vector<int>(i * (i - 1) / 2 + 1);
        for (int j = 1; j <= i; j++) {
            for (int need = 0; need + j - 1 <= i * (i - 1) / 2 && need <= (i - 1) * (i - 2) / 2; need++) {
                ad(num_per[i][need + j - 1], num_per[i - 1][need]);
            }
        }
        pref[i] = vector<int>(i * (i - 1) / 2 + 1);
        for (int j = 0; j <= i * (i - 1) / 2; j++)
            pref[i][j] = add((j == 0 ? 0 : pref[i][j - 1]), num_per[i][j]);
    }
//    for (auto to:num_per[4])
//        cout << to << " ";
//    cout << '\n';
    int ans = 0;
    vector<int> fact(n + 1);
    fact[0] = 1;
    for (int sz = 2; sz <= n; sz++) {
        for (int delta = 1; delta <= sz - 1; delta++) {
            int sum = 0;
            for (int can = 0; can <= (sz - 1) * (sz - 2) / 2; can++) {
                if (can - delta - 1 < 0)
                    continue;
                // can>can2+delta
                // can-delta>can2
                // can2=can-delta-1
//                for (int can2 = 0; can2 <= (sz - 1) * (sz - 2) / 2 && can > can2 + delta; can2++) {
//                ad(sum, mult(num_per[sz - 1][can], num_per[sz - 1][can2]));
                ad(sum, mult(num_per[sz - 1][can], pref[sz - 1][min((sz - 1) * (sz - 2) / 2, can - delta - 1)]));
//                }
            }
//                cout << sum << " " << fir << " " << sec << '\n';
            ad(ans, mult(sz - delta, mult(sum, A(n, sz))));
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
//    cin >> _t;
    while (_t--)
        solve();
#ifdef Mip182
    cout << '\n' << "Time : " << (double) (clock()) / CLOCKS_PER_SEC << '\n';
#endif
}