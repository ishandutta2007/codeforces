#include <bits/stdc++.h>
#define mp make_pair
#define eb emplace_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define svec(x) sort(all(x))
#define press(x) x.erase(unique(all(x)), x.end());
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<int, LL> pil;
typedef pair<LL, int> pli;
typedef pair<LL, LL> pll;
const int INF=1e9;
const LL mod=998244353;

LL fac[300010], invfac[300010], dp[300010], fac2[300010], pw[300010];

LL power(LL a, LL b){
    if(!b)return 1ll;
    LL ret=power(a, b/2);
    if(b%2)return ret*ret%mod*a%mod;
    return ret*ret%mod;
}
LL C(int a, int b){return fac[a]*invfac[b]%mod*invfac[a-b]%mod;}
int n;

void solve(){
    LL ans=0;
    scanf("%d", &n);
    for(int i=0; i*4<=n; i++){
        LL tmp=C(n-2*i, 2*i);
        tmp*=fac[2*i];
        tmp%=mod;
        tmp*=power(pw[i], mod-2);
        tmp%=mod;
        tmp*=invfac[i];
        tmp%=mod;
        tmp*=dp[n-4*i];
        tmp%=mod;
        tmp*=pw[i];
        tmp%=mod;
        ans+=tmp;
        ans%=mod;
    }
    printf("%lld\n", ans);
}

int main(){
    fac[0]=1;
    dp[0]=dp[1]=1;
    for(int i=2; i<=300000; i++)dp[i]=(dp[i-1]+dp[i-2]*(i-1))%mod;
    for(int i=1; i<=300000; i++)fac[i]=fac[i-1]*i%mod;
    for(int i=0; i<=300000; i++)invfac[i]=power(fac[i], mod-2);
    fac2[0]=fac2[1]=1;
    for(int i=2; i<=300000; i++)fac2[i]=fac2[i-2]*i%mod;
    pw[0]=1;
    for(int i=1; i<=300000; i++)pw[i]=pw[i-1]*2%mod;
    int t;
    scanf("%d", &t);
    while(t--)solve();
}