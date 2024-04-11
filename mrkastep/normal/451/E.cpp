#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define ll long long int
#define For(i,n) for(i=0;i<(n);i++)
#define FOR(i,a,b) for(i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define x first
#define y second

const int mod=1e9+7;
const int INF=2e9;
const ll LONGINF=4e18;

void prod(ll deg,map<ll,ll> m,map<ll,ll> &ans){
    for(auto it=m.begin();it!=m.end();it++){
        ans[it->x+deg]-=it->y;
        if(ans[it->x+deg]<0){
            ans[it->x+deg]+=mod;
        }
    }
}

ll inv[60];

ll C(ll n,ll k){
    if(k<0) return 0;
    if(n<0) return 0;
    n%=mod;
    k%=mod;
    int i;
    if(k>n) return 0;
    ll ans=1;
    For(i,k){
        ans=ans*(n-i)%mod;
        ans=ans*inv[i+1]%mod;
    }
    return ans;
}


void solve(int n){
    int i,j;
    ll s,a;
    map<ll,ll> m;
    scanf("%I64d",&s);
    m[0]=1;
    For(i,n){
        scanf("%I64d",&a);
        prod(a+1,m,m);
    }
    inv[1]=1;
    FOR(i,2,60){
        inv[i]=-(mod/i*inv[mod%i]%mod)+mod;
    }
    ll ans=0;
    for(auto it=m.begin();it!=m.end();it++){
        ans+=(it->y*C(s-it->x-1+n,n-1)+(ll)mod*mod)%mod;
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
    char c[100100];
    string s;
    while(scanf("%d",&n)==1){
        solve(n);
    }




    return 0;
}