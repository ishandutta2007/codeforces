#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define ll long long int
#define For(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define x first
#define y second

const int mod=1e9+7;
const int INF=2e9;
const ll LONGINF=4e18;

ll inv[100100],fct[100100],invfct[100100];
ll c[2222];

ll C(ll n,ll k){
    return fct[n]*invfct[n-k]%mod*invfct[k]%mod;
}

void solve(int n){
    int k;
    ll ans;
    inv[1]=1;
    fct[0]=1;
    fct[1]=1;
    invfct[0]=1;
    invfct[1]=1;
    FOR(i,2,100100){
        inv[i]=-((ll)mod/i*inv[mod%i]%mod)+mod;
        fct[i]=fct[i-1]*i%mod;
        invfct[i]=invfct[i-1]*inv[i]%mod;
    }
    ans=0;
    FOR(i,1,n+1){
        ans+=C(n-1,i-1)*C(n,i)%mod;
        ans%=mod;
    }
    ans*=2;
    ans-=n;
    ans%=mod;
    printf("%I64d",ans);





}


int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef HOME
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    int n;
    ll a;
    char c[200200];
    string s;
    while(scanf("%d",&n)==1) solve(n);



    return 0;
}