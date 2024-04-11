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
const LL LLINF=1e18;
const LL mod=1e9+7;

int n, arr[200010];
LL fac[500010], ans;
LL power(LL a, LL b){
    if(b==0)return 1ll;
    LL tmp=power(a, b/2);
    if(b%2)return tmp*tmp%mod*a%mod;
    return tmp*tmp%mod;
}
LL C(int a, int b){
    return fac[a]*power(fac[b], mod-2)%mod*power(fac[a-b], mod-2)%mod;
}

int main(){
    fac[0]=1ll;
    for(int i=1; i<=500000; i++)fac[i]=fac[i-1]*(LL)i%mod;
    scanf("%d", &n);
    for(int i=0; i<=n; i++){
        int a;
        scanf("%d", &a);
        ans+=C(a+i, i+1);
        ans%=mod;
    }
    printf("%lld", ans);
}