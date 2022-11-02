
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

ll dist(pair<ll,ll> a,pair<ll,ll> b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

double dist(pair<ll,ll> p,pair<ll,ll> a,pair<ll,ll> b){
    ll A,B,C;
    A=a.y-b.y;
    B=b.x-a.x;
    C=a.x*b.y-a.y*b.x;
    return abs(A*p.x+B*p.y+C)/sqrt((double)(A*A+B*B));
}

double scal(pair<ll,ll> a,pair<ll,ll> b){
    return a.x*b.x+a.y*b.y;
}

pair<ll,ll> operator-(pair<ll,ll> a,pair<ll,ll> b){
    return mp(a.x-b.x,a.y-b.y);
}

void solve(){
    int n;
    pair<ll,ll> P,p,pr,f;
    double mn=LONGINF,mx=0;
    scanf("%d%I64d%I64d",&n,&P.x,&P.y);
    For(i,n){
        scanf("%I64d%I64d",&p.x,&p.y);
        if(i==0){
            f=p;
        }
        else{
            if(scal(pr-p,pr-P)>0&&scal(p-pr,p-P)>0){
                mn=min(mn,dist(P,p,pr));
                mx=max(mx,dist(P,p,pr));
            }
        }
        mn=min(mn,sqrt((double)dist(p,P)));
        mx=max(mx,sqrt((double)dist(p,P)));
        pr=p;
    }
    if(scal(p-P,p-f)>0&&scal(f-P,f-p)>0){
        mn=min(mn,dist(P,p,f));
        mx=max(mx,dist(P,p,f));
    }
    printf("%.10lf",PI*(mx*mx-mn*mn));

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