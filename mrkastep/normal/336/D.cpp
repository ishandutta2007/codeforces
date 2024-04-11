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

ll inv[200200],fct[200200],invfct[200200];
ll c[2222];

ll C(ll n,ll k){
    return fct[n]*invfct[n-k]%mod*invfct[k]%mod;
}

void solve(int n){
    int m,g;
    ll c,ans=0;
    scanf("%d%d",&m,&g);
    inv[1]=1;
    fct[0]=1;
    fct[1]=1;
    invfct[0]=1;
    invfct[1]=1;
    FOR(i,2,200200){
        inv[i]=-((ll)mod/i*inv[mod%i]%mod)+mod;
        fct[i]=fct[i-1]*i%mod;
        invfct[i]=invfct[i-1]*inv[i]%mod;
    }
    if(m==0){
        if(n%2==1-g){
            printf("1");
        }
        else{
            printf("0");
        }
        return;
    }
    c=C(n+m-1,n);
    For(i,n+1){
        if(m==1&&i==n){
            if((n+1)%2==g){
                ans++;
                ans%=mod;
            }
            continue;
        }
        if(i%2==g){
            ans+=c;
            ans%=mod;
        }
        c=c*inv[n+m-i-1]%mod*(n-i)%mod;;
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