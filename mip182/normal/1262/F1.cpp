#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vll vector <ll>
#define vpii vector <pair <int,int> >
#define vpll vector <pair <long long,long long> >
#define vvi vector <vector <int> >
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 5e5+100;
const ll INF = 1e9;
const ll kek=998244353;
const ll mod1=1e9+7;
const ll mod2=2e9+11;

ll binpow(ll a,ll b)
{
    if(a==0)
        return 1;
    if (a==1)
        return b;
    ll q=(binpow(a/2,b))%kek;
    if (a%2==0)
        return (q*q)%kek;
    else
        return (((q*q)%kek)*b)%kek;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    ll C[n+1][n+1];
    for (int f = 0; f <= n; ++f) {
        C[f][0] = C[f][f] = 1;
        for (int u = 1; u < f; ++u) {
            C[f][u] = C[f - 1][u - 1] + C[f - 1][u];
            C[f][u] %= kek;
        }
    }
    vector<ll> h(n);
    rep(i, n)cin >> h[i];
    vector<int> good(n, 0);
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        if (h[i] == h[j])
            good[i] = 1;
    }
    for (int i = 0; i < n; i++) {
        if (good[i] == 1)
            cnt++;
    }
    ll ans = 1;
    ans *= binpow(cnt, k);
    ll t = n - cnt;
    ll sum = 0;
    for (int i=t;i>=1;i--)
    {
        ll q=C[t][i];
        ll x=0;
        for (int j=0;j<=min((ll)(i-1),t-i);j++)
        {
            x+=(C[t-i][j]*binpow(t-i-j,k-2))%kek;
            x%=kek;
        }
        sum+=(q*x)%kek;
        sum%=kek;


    }
    cout<<(ans*sum)%kek;
}