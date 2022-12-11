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
    bool one_more = false;
    if ((n & 1) && s[n / 2] == '0')
        one_more = true;
    int cnt_zero = 0;
    int cnt_good = 0;
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        if (s[i] == '0' && s[j] == '0')
            cnt_zero++;
        else if (s[i] + s[j] == '0' + '1')
            cnt_good++;
    }
//    cout << cnt_good << " " << cnt_zero << '\n';
    bool can = false;
    bool now_turn = true;
    int a = 0, b = 0;
    while (cnt_zero > 0 || cnt_good > 0) {
        if (cnt_good != 0 && !can) {
            can = true;
        } else if (cnt_good == 0 && one_more) {
            a += now_turn;
            b += !now_turn;
            can = false;
            one_more = false;
        } else {
            a += now_turn;
            b += !now_turn;
            if (cnt_zero > 0) {
                cnt_zero--;
                cnt_good++;
            } else {
                cnt_good--;
            }
            can = false;
        }
        now_turn = !now_turn;
    }
    a += now_turn && one_more;
    b += !now_turn && one_more;
    cout << (a == b ? "DRAW\n" : (a > b) ? "BOB\n" : "ALICE\n");
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