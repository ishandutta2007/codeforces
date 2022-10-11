#include <bits/stdc++.h>
#define TASK "1334E"
#define pb push_back
#define ii pair<int,int>
#define ll long long
#define F first
#define S second
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FOr(i, a, b) for (int i=a; i<b ; i++)
#define FOD(i, a, b) for (int i=a; i>=b; i--)
#define FOd(i, a, b) for (int i=1; i>b ; i--)
using namespace std;
const ll MOD = 998244353;
ll c[51][51];
ll D, U, V;
ll cnt, Q;
ll f[51],g[51];
map<ll,ll> rr;
ll solve(ll v)
{
    if (rr[v]) return rr[v];
    ll sv = v;
    FOR (i, 1, cnt) {
        g[i] = 0;
        while (v % f[i] == 0) {
            ++g[i];
            v /= f[i];
        }
    }
    ll  ans = 1;
    int sum = 0;
    FOR (i, 1, cnt)
        sum += g[i];

    FOR (i, 1, cnt) {
        ans *= c[g[i]][sum];
        ans %= MOD;
        sum -= g[i];
    }
    rr[sv]=ans;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>D>>Q;
    cnt=0;
    for (ll i=2; i*i<=D; i++)
        if (D % i == 0) {
            f[++cnt]=i;
            while (D % i == 0)
                D/=i;
        }

    if (D > 1)
        f[++cnt]=D;


    FOR(i, 0, 50) c[0][i] = 1;

    FOR(i, 1, 50)
        FOR(j, i, 50)
            c[i][j]=(c[i][j-1] + c[i-1][j - 1]) % MOD;

    while (Q--) {
        cin >> U >> V;
        ll t = __gcd(U, V);
        ll ans;
        if (t != U && t != V)
            ans = solve(U/t)*solve(V/t) % MOD;
        else {
            if (U > V) swap(U, V);
            ans = solve(V/U);
        }
        cout << ans << "\n";
    }
}