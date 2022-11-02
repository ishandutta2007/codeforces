#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <map>
#include <time.h>
#include <string>
#include <algorithm>
#include <queue>
#include <assert.h>
#include <math.h>
#include <complex>

#pragma warning(disable:4996)

using namespace std;

#define For(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(v) (v).begin(),(v).end()

typedef long long int ll;
typedef vector<ll> lll;

const int INF=1e9;
const int mod=1e9+7;
const ll LONGINF=4e18;
const double eps=1e-9;
const double PI=3.1415926535897932384626433832795;

ll f[1001000],rf[1001000],r[1001000];

ll C(ll n,ll k){
    return f[n]*rf[k]%mod*rf[n-k]%mod;
}

ll pw(ll n,ll d){
    ll ans=1;
    for(int i=60;i>=0;i--){
        ans=ans*ans%mod;
        if(d&(1ll<<i)) ans=ans*n%mod;
    }
    return ans;
}

void solve(){
    ll p,k,d=0,t=1,ans=0;
    scanf("%I64d%I64d",&p,&k);
    if(k==0){
        printf("%I64d",pw(p,p-1));
        return;
    }
    if(k==1){
        printf("%I64d",pw(p,p));
        return;
    }
    while(d==0||t!=1){
        d++;
        t*=k;
        t%=p;
    }
    int g=(p-1)/d;
    r[0]=0,r[1]=1;
    FOR(i,2,1001000){
        r[i]=((ll)mod*mod-mod/i*r[mod%i])%mod;
    }
    f[0]=1;
    FOR(i,1,1001000) f[i]=f[i-1]*i%mod;
    rf[0]=1;
    FOR(i,1,1001000) rf[i]=rf[i-1]*r[i]%mod;
    For(i,g+1){
        ans+=C(g,i)*pw(p-1,i);
        ans%=mod;
    }
    printf("%I64d",ans);


}

int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef _DEBUG
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    solve();
    return 0;
}