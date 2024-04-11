
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
typedef complex<double> point;

const int INF=1e9; 
const int mod=1e9+7; 
const ll LONGINF=4e18; 
const double eps=1e-4;
const double PI=3.1415926535897932384626433832795;

ll a[100100],A,sb[100100],ind[100100];

bool cmp(ll a1,ll b1){return a[a1]<a[b1];}

void solve(){
    int n;
    ll cf,cm,m,s=0,t=0;
    scanf("%d%I64d%I64d%I64d%I64d",&n,&A,&cf,&cm,&m);
    For(i,n){
        scanf("%I64d",&a[i]);
        s+=a[i];
        ind[i]=i;
    }
    if(m>=A*n-s){
        printf("%I64d\n",n*cf+cm*A);
        For(i,n) printf("%I64d ",A);
        return;
    }
    ll ans=0,ansi=0;
    sort(ind,ind+n,cmp);
    sb[0]=a[ind[0]];
    FOR(i,1,n) sb[i]=sb[i-1]+a[ind[i]];
    s=m;
    For(i,n+1){
        if(i>0) s-=A-a[ind[n-i]];
        if(s<0) break;
        int l=0,r=n-i;
        while(r-l>1){
            int c=(l+r)/2;
            if(a[ind[c]]*(c+1)-sb[c]<=s) l=c;
            else r=c;
        }
        if(ans<i*cf+cm*(a[ind[l]]+(s-(a[ind[l]]*(l+1)-sb[l]))/(l+1))){
            ans=i*cf+cm*(a[ind[l]]+(s-(a[ind[l]]*(l+1)-sb[l]))/(l+1));
            ansi=i;
        }
    }
    s=m;
    For(i,ansi) s-=A-a[ind[n-i-1]];
    int l=0,r=n-ansi;
    while(r-l>1){
        int c=(l+r)/2;
        if(a[ind[c]]*(c+1)-sb[c]<=s) l=c;
        else r=c;
    }
    For(i,l+1) a[ind[i]]=(a[ind[l]]+(s-(a[ind[l]]*(l+1)-sb[l]))/(l+1));
    For(i,ansi) a[ind[n-i-1]]=A;
    printf("%I64d\n",ans);
    For(i,n){
        printf("%I64d ",a[i]);
    }
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