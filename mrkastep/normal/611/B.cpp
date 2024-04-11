
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

ll f(ll a){
    ll t=1,ans=0;
    while(t<=a){
        t<<=1;
        ll s=t-1;
        For(i,62){
            if((1ll<<(i+1))<s&&(s^(1ll<<(i)))<=a){
                ans++;
            }
        }
    }
    return ans;
}



void solve(){
    ll a,b;
    cin >> a >> b;
    cout << f(b)-f(a-1) << endl;
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