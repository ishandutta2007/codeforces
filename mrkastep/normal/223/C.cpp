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

int inv[2222];
ll c[2222];

ll C(ll n,ll k){
    ll ans=1;
    n%=mod;
    k%=mod;
    For(i,k){
        ans*=(n-i);
        ans%=mod;
        ans*=inv[1+i];
        ans%=mod;
    }
    return ans;
}

void solve(int n){
    int k;
    ll a[2222],ans[2222];
    inv[1]=1;
    FOR(i,2,2222){
        inv[i]=-((ll)mod/i*inv[mod%i]%mod)+mod;
    }
    c[0]=1;
    scanf("%d",&k);
    For(i,n) scanf("%I64d",&a[i]);
    For(i,n+5){
        c[i]=C(k+i-1,i);
    }
    For(i,n){
        ans[i]=0;
        For(j,i+1){
            ans[i]+=a[i-j]*c[j]%mod;
            ans[i]%=mod;
        }
    }
    For(i,n){
        printf("%I64d ",ans[i]);
    }







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