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
const int MAXN = 4e5 + 100;
const ll INF = 1e9;
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 21;

int add(int a, int b) {
    a += b;
    if (a >= mod1)
        return a - mod1;
    return a;
}

int mult(int a, int b) {
    return 1ll * a * b % mod1;
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

int bin_pow(int base, ll deg) {
    if (deg == 0)
        return 1;
    int t = bin_pow(base, deg / 2);
    if (deg & 1)
        return 1ll * t * t % mod1 * base % mod1;
    else
        return 1ll * t * t % mod1;
}

int fact[MAXN];
int ifact[MAXN];

int C(int n, int k) {
    if (k > n)
        return 0;
    int ans = fact[n];
    ans = mult(ans, ifact[k]);
    return mult(ans, ifact[n - k]);
}

void solve() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++)
        fact[i] = mult(fact[i - 1], i);
    ifact[MAXN - 1] = bin_pow(fact[MAXN - 1], mod1 - 2);
    for (int i = MAXN - 2; i >= 0; i--)
        ifact[i] = mult(ifact[i + 1], i + 1);
    int n;
    cin >> n;
    vector<ll> a(n);in(a);
    ll need = accumulate(all(a), 0ll);
    if (need % n) {
        cout << 0 << '\n';
        return;
    }
    need /= n;
    //    ,       
    //       
    vector<ll> b(n);
    for (int i = 0; i < n; i++)
        b[i] = a[i] - need;
    int more = 0, less = 0;
    int zero = 0;
    for (int i = 0; i < n; i++) {
        more += b[i] > 0;
        less += b[i] < 0;
        zero += b[i] == 0;
    }
    //  more  less   
    //      ,   ,    ,   
    int ans = 0;
    int what_mult = C(more + less + zero, zero);
    //        
    map<int, int> for_more, for_less;
    for (auto to:b) {
        if (to == 0)
            continue;
        if (to > 0)
            for_more[to]++;
        else
            for_less[to]++;
    }
    int cnt_more = fact[more], cnt_less = fact[less];
    for (auto to:for_more)
        cnt_more = mult(cnt_more, ifact[to.se]);
    for (auto to:for_less)
        cnt_less = mult(cnt_less, ifact[to.se]);
    if (more == 1 || less == 1) {
        if (more == 1)
            swap(more, less), swap(cnt_more, cnt_less);
        ans = add(ans, mult(more + 1, cnt_more));
//        if (more == 1 && less == 1)
//            ans = sub(ans, 1);
    } else {
        if (more > 0 && less > 0) {
            ans = add(ans, mult(2, mult(cnt_more, cnt_less)));
        } else {
            ans = add(cnt_more, cnt_less);
            ans = sub(ans, 1);
        }
    }
//    int total = 0;
//    total = mult(more + 1, cnt_more);
//    total = mult(total, cnt_less);
//    ans = add(ans, total);
//    {
//        total = 0;
//        swap(cnt_more, cnt_less);
//        swap(more,less);
//        total = mult(more + 1, cnt_more);
//        total = mult(total, cnt_less);
//        ans = add(ans, total);
//    }
    ans = mult(ans, what_mult);
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