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

bool prime(int a){
    if(a==1) return false;
    FOR(i,2,(int)sqrt((double)a)+1){
        if(a%i==0) return false;
    }
    return true;
}

ll gdc(ll a,ll b){
    while(a>0&&b>0){
        if(a>b) a%=b;
        else b%=a;
    }
    return max(a,b);
}

void sol(){
    ll n,i,pr,nx;
    ll chisl,znam,g;
    scanf("%I64d",&n);
    i=n;
    while(!prime(i)) i--;
    pr=i;
    i=n+1;
    while(!prime(i)) i++;
    nx=i;
    chisl=(pr-2)*nx+2*(n-pr+1);
    znam=2*pr*nx;
    g=gdc(chisl,znam);
    chisl/=g;
    znam/=g;
    printf("%I64d/%I64d\n",chisl,znam);
}



void solve(int n){
    int nxt,pr;
    For(i,n) sol();





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