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

void pr(int a,vector<int> &ans){
    int t=(int)sqrt((double)a)+1;
    FOR(i,2,t){
        if(a%i==0) ans.pb(i);
        while(a%i==0){
            a/=i;
        }
    }
    if(a>1){
        ans.pb(a);
    }
}

int prr(int a){
    int t=(int)sqrt((double)a)+1,c;
    vector<int> ans;
    FOR(i,2,t){
        c=0;
        if(a%i==0) ans.pb(i);
        while(a%i==0){
            c++;
            a/=i;
        }
        if(c>1) return 0;
    }
    if(a>1){
        ans.pb(a);
    }
    return (1-ans.size()%2)*2-1;
}

void div(int a,vector<int> &ans){
    int t=(int)sqrt((double)a)+1;
    FOR(i,1,t){
        if(a%i==0){
            ans.pb(i);
            if(ans.back()!=a/i){
                ans.pb(a/i);
            }
        }
    }
}

void sol(){
    int n,k;
    vector<int> p,d;
    scanf("%d%d",&n,&k);
    ll ans=0;
    pr(n,p);
    div(n,d);
    For(i,d.size()){
        ans+=C(d[i]-1,k-1)*mu[n/d[i]];
        ans=((ll)mod*mod+ans)%mod;
    }
    printf("%I64d\n",ans);
}





void solve(int n){
    int m,g;
    ll c,ans=0;
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
    FOR(i,1,100100){
        mu[i]=prr(i);
    }
    For(i,n){
        sol();
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