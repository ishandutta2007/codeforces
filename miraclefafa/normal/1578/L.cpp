//Awwawa! Dis cold yis ratten buy Pikachu!
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 1000000007
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 100005;
vi fac[maxn];
int ph[maxn];
int a[maxn];

int cnt[maxn];
ll cal(vi a) {
    ll s = 0;
    for (auto v : a) {
        for (auto t : fac[v]) {
            int h = (2 * cnt[t] + 1);
            s = (s + 1ll * ph[t] * h) % mod;
            cnt[t] += 1;
        }
    }
    for (auto v : a)
        for (auto t : fac[v]) 
            cnt[t] = 0;
    return s;
}
int main() {
    for (int i = 1; i < maxn; i++)
        for (int j = 1; j * i < maxn; j += 1)
            fac[i * j].pb(i);
    ph[1] = 1;
    for (int i = 2; i < maxn; i++) {
        ph[i] = i;
        for (auto v : fac[i]) {
            if (v == i) continue;
            ph[i] -= ph[v];
        }
    }
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    ll ans = 0;
    for (int j = 1; j <= n; j++) {
        vi cur;
        for (int m = j; m <= n; m += j)
            cur.pb(a[m]);
        ans += 1ll * cal(cur) * ph[j] % mod;
        ans %= mod;
    }
    cout << ans << endl;
    return (0-0); //<3
}