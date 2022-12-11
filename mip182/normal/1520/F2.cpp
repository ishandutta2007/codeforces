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
const int MAXN = 2e5 + 100;
const ll INF = 1e9;
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 21;
int f[MAXN];

void add(int pos, int x) {
    for (; pos < MAXN; pos |= pos + 1)
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

unordered_map<int, int> qu;

int ask(int l, int r) {
    if (qu.find(r) != qu.end()) {
        return qu[r] + res(r);
    }
    cout << "? " << l << " " << r << endl;
    int x;
    cin >> x;
    qu[r] = x - res(r);
    return x;
}

void done(int pos) {
    cout << "! " << pos << endl;
}

void solve() {
    int n, t;
    cin >> n >> t;
    while (t--) {
        int l = 1, r = n;
        int ans = -1;
        int k;
        cin >> k;
        while (l <= r) {
            int mid = ((l + r) >> 1);
            if (mid - ask(1, mid) >= k)
                ans = mid, r = mid - 1;
            else
                l = mid + 1;
        }
        assert(ans != -1);
        done(ans);
        add(ans, 1);
    }
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