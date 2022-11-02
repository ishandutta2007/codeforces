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

ll inv[200200],fct[200200],invfct[200200],mu[100100];
ll c[2222];

ll C(ll n,ll k){
    if(n<k) return 0;
    return fct[n]*invfct[n-k]%mod*invfct[k]%mod;
}

void solve(int n){
    int p,a,b=0;
    ll ans=0;
    map<int,int> m;
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
    For(i,n) m[i]=1;
    For(i,n){
        scanf("%d",&p);
        p--;
        if(p<0){
            b++;
        }
        else{
            m.erase(p);
            m.erase(i);
        }
    }
    a=m.size();
    For(i,a+1){
        ans=ans+((1-i%2)*2-1)*(C(a,i)*fct[b-i]%mod)%mod+(ll)mod*mod;
        ans%=mod;
    }
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