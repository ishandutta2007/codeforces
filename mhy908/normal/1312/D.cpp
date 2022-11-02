#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define sortvec(x) sort(all(x))
#define compress(x) x.erase(unique(all(x)), x.end())
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<int, LL> pil;
typedef pair<LL, int> pli;
const LL llinf=1987654321987654321;
const int inf=2000000000;
const LL mod=998244353;
int n, m;
LL fac[200010];
LL power(LL a, LL b){
    if(!b)return 1ll;
    LL ret=power(a, b/2);
    if(b%2)return ret*ret%mod*a%mod;
    return ret*ret%mod;
}
int main(){
    scanf("%d %d", &n, &m);
    fac[0]=1;
    for(int i=1; i<=200000; i++)fac[i]=fac[i-1]*(LL)i%mod;
    printf("%lld", fac[m]*power(fac[n-1], mod-2)%mod*power(fac[m-n+1], mod-2)%mod*power(2ll, (LL)n-3)%mod*(LL)(n-2)%mod);
}