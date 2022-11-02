
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

int t[1001000],p[100100],d[100100];

void solve(){
    int n,a,b;
    scanf("%d",&n);
    For(i,1001000) t[i]=-1;
    For(i,n){
        scanf("%d%d",&a,&b);
        p[i]=b;
        t[a]=i;
    }
    a=-1;
    For(i,1001000){
        if(t[i]!=-1){
            a=t[i];
        }
        t[i]=a;
    }
    For(i,n){
        d[i]=0;
    }
    int ans=0;
    For(i,1001000){
        if(t[i]!=-1&&(i==0||t[i]!=t[i-1])){
            d[t[i]]=1;
            if(i-p[t[i]]-1>=0) d[t[i]]+=d[t[i-p[t[i]]-1]];
            ans=max(ans,d[t[i]]);
        }
    }
    printf("%d",n-ans);
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