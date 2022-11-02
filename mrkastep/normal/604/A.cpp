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

const int INF=1e9; 
const int mod=1e9+7; 
const ll LONGINF=4e18; 
const double eps=1e-9; 
const double PI=3.1415926535897932384626433832795;

void solve(){
    int w[5],m[5],h[2],b[5];
    For(i,5){
        scanf("%d",&m[i]);
        b[i]=(i+1)*500;
    }
    For(i,5) scanf("%d",&w[i]);
    For(i,2) scanf("%d",&h[i]);
    int ans=0;
    For(i,5){
        ans+=max(3*b[i]/10,b[i]-b[i]/250*m[i]-50*w[i]);
    }
    ans+=100*h[0]-50*h[1];
    printf("%d",ans);

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