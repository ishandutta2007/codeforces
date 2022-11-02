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

int n;
LL pw[70], cnt[70], arr[500010], ans;

void solve(){
    scanf("%d", &n);
    ans=0;
    memset(cnt, 0, sizeof cnt);
    for(int i=1; i<=n; i++){
        LL x;
        scanf("%lld", &arr[i]);
        x=arr[i];
        for(int j=0; ; j++){
            if(!x)break;
            if(x%2)cnt[j]++;
            x/=2;
        }
    }
    for(int i=1; i<=n; i++){
        LL asum=0, osum=0, x=arr[i];
        for(int j=0; j<=60; j++){
            if(x%2){
                asum+=pw[j]*cnt[j]%mod;
                asum%=mod;
                osum+=pw[j]*(LL)n%mod;
                osum%=mod;
            }
            else{
                osum+=pw[j]*cnt[j]%mod;
                osum%=mod;
            }
            x/=2;
        }
        ans+=asum*osum%mod;
        ans%=mod;
    }
    printf("%lld\n", ans);
}

int main(){
    pw[0]=1;
    for(int i=1; i<=60; i++)pw[i]=pw[i-1]*2ll%mod;
    int t;
    scanf("%d", &t);
    while(t--)solve();
}