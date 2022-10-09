#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll P = 29;
const int mod = 1e9+7;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 200100
ll pref[maxn], suf[maxn + 3];
int cnt[maxn], tab[maxn], n;
ll A[maxn];
ll potmod(ll a, ll b, ll m) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = (ret * a) % m;
        b >>= 1;
        a = ( a * a) %m;
    }
    return ret;
}
ll summod(ll pot, ll alfa) {
    ll sum = (alfa) * (alfa + 1) / 2;
    return potmod(pot, sum, mod);
}

int main()
{
    boost;
    cin >> n;
    for (int i=1; i<=n; ++i) cin >> tab[i], cnt[tab[i]]++;
    sort(tab + 1, tab + n + 1);
    pref[0] = suf[maxn] = 1;
    for (int i=1; i<maxn; ++i) pref[i] = pref[i-1] * (cnt[i] + 1) % (mod - 1);
    for (int i=maxn-1; i>0; --i) suf[i] = suf[i + 1] * (cnt[i] + 1) % (mod - 1);
    ll res = 1;
    for (int i=1; i<maxn; ++i)
    {
        if (cnt[i] < 1) continue;
        ll S = summod(i, cnt[i]);
        ll wyk = (pref[i-1] * suf[i + 1]) % (mod - 1);
        res = res * (potmod(S, wyk, mod))%mod;
    }
    cout << res;
}