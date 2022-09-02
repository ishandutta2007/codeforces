#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<ctype.h>
using namespace std;

#define X first
#define Y second
typedef long long ll;
typedef pair<int,int> Pi;

const int MOD = 1e9+7;

int L, R;
int inp[100010];
int w[100010];
int n;
int Fact[200020];

int pw(int x,int y)
{
    ll x1 = x, res = 1;
    while(y){
        if(y&1)res = (res * x1) % MOD;
        x1 = (x1*x1) % MOD;
        y >>= 1;
    }
    return (int)res;
}

int nCr(int n,int r)
{
    ll ret = (ll)Fact[n] * pw(Fact[n-r], MOD-2);
    ret %= MOD;
    ret *= pw(Fact[r], MOD-2);
    ret %= MOD;
    return (int)ret;
}

int solve(int L,int R,int now)
{
    if(L < 1 || R > n)return 0;
    int i;
    for(i=now+1;i<=n;i++){
        if(w[i])break;
    }
    if(i == n+1)return nCr(n - (R-L+1), n-R);
    if(w[i] > R){
        int tot = i - now - 1;
        int r = w[i] - R - 1;
        if(r > tot)return 0;
        ll res = nCr(tot, r);
        return (res*solve(w[i]-i+1,w[i],i)) % MOD;
    }
    else if(w[i] < L){
        int tot = i - now - 1;
        int l = L - w[i] - 1;
        if(l > tot)return 0;
        ll res = nCr(tot, l);
        return (res*solve(w[i],w[i]+i-1,i)) % MOD;
    }
    else return 0;
}

int main()
{
    scanf("%d",&n);
    int i;
    Fact[0] = Fact[1] = 1;
    for(i=2;i<=200000;i++)Fact[i] = ((ll)i*Fact[i-1]) % MOD;
    for(i=1;i<=n;i++)scanf("%d",inp+i);
    for(i=1;i<=n;i++)if(inp[i])w[inp[i]] = i;
    int L, R;
    if(!w[1]){
        for(i=1;i<=n;i++)if(w[i])break;
        if(i == n+1){printf("%d",pw(2,n-1));return 0;}
        int t = i;
        L = w[t] - t + 1;
        R = w[t];
        ll ans = (ll)pw(2,t-2) * solve(L,R,t);
        ans %= MOD;
        R = w[t] + t - 1;
        L = w[t];
        ans += (ll)pw(2,t-2) * solve(L,R,t);
        ans %= MOD;
        printf("%lld",ans);
    }
    else{
        printf("%d",solve(w[1],w[1],1));
    }
    return 0;
}