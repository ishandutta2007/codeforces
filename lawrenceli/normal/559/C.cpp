#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 2005;
const int maxm = 200100;
const int mod = 1e9 + 7;

int h, w, n;
pii ar[maxn];
int dp[maxn];
int fact[maxm], invfact[maxm];

int C(int a, int b) { return ll(fact[a])*invfact[b]%mod*invfact[a-b]%mod; }

int exp(int a, int b) {
    if (!b) return 1;
    if (b&1) return ll(exp(a, b-1))*a%mod;
    int res = exp(a, b>>1);
    return ll(res)*res%mod;
}

int main() {
    fact[0] = 1;
    for (int i=1; i<maxm; i++) fact[i] = ll(fact[i-1])*i%mod;
    for (int i=0; i<maxm; i++) invfact[i] = exp(fact[i], mod-2);

    cin >> h >> w >> n;
    for (int i=0; i<n; i++) {
        cin >> ar[i].fi >> ar[i].se;
        ar[i].fi--, ar[i].se--;
    }
    ar[n].fi = h-1, ar[n].se = w-1;
    n++;
    sort(ar, ar+n);

    for (int i=0; i<n; i++) {
        dp[i] = C(ar[i].fi+ar[i].se, ar[i].fi);
        for (int j=0; j<i; j++)
            if (ar[j].se <= ar[i].se)
                dp[i] = (dp[i]+mod-ll(dp[j])*C(ar[i].fi-ar[j].fi+ar[i].se-ar[j].se, ar[i].fi-ar[j].fi)%mod)%mod;
    }

    assert(ar[n-1].fi == h-1 && ar[n-1].se == w-1);
    cout << dp[n-1] << '\n';
}