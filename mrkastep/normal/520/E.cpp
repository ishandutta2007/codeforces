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

pair<int,int> euclid(int a,int b){
    if(b>a){
        pair<int,int> p1;
        p1=euclid(b,a);
        return mp(p1.y,p1.x);
    }
    if(b==0){
        return mp(1,0);
    }
    int c=a%b;
    pair<int,int> p=euclid(b,c);
    return mp(p.y,p.x-p.y*(a/b));
}

int obr[100100],fct[100100],sb[100100],ck[100100],ck1[100100],obrfct[100100];

void solve(int n){
    int k,i;
    ll sm,pr,ans=0,deg=1;
    scanf("%d",&k);
    char c[100100];
    string s;
    gets(c);
    gets(c);
    s=c;
    obr[1]=1;
    FOR(i,2,n){
        obr[i]=((ll)mod*mod-(ll)(mod/i)*obr[mod%i])%mod;
    }
    fct[0]=1;
    FOR(i,1,n+1){
        fct[i]=(ll)fct[i-1]*i%mod;
    }
    obrfct[0]=1;
    FOR(i,1,n+1){
        obrfct[i]=(ll)obrfct[i-1]*obr[i]%mod;
    }
    For(i,n){
        if(i<k){
            ck[i]=0;
        }
        else{
            ck[i]=(ll)fct[i]*obrfct[k]%mod*obrfct[i-k]%mod;
        }
        if(i<k-1){
            ck1[i]=0;
        }
        else{
            ck1[i]=(ll)fct[i]*obrfct[k-1]%mod*obrfct[i-k+1]%mod;
        }
    }
    deg=1;
    sm=0;
    pr=ck[n-1];
    For(i,n){
        ans+=(ll)(sm+pr)*(s.back()-'0')%mod;
        ans%=mod;
        sm+=ck1[n-2-i]*deg;
        sm%=mod;
        deg*=10;
        deg%=mod;
        pr=ck[n-2-i]*deg%mod;
        s.pop_back();
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