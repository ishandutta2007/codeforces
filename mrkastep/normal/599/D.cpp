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

using namespace std;

#define For(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define ll long long int
#define all(v) (v).begin(),(v).end()

const int INF=1e9;
const int mod=1e5+3;
const ll LONGINF=4e18;
const double eps=1e-9;
const double PI=3.1415926535897932384626433832795;

void solve(){
    ll a;
    scanf("%I64d",&a);
    vector<pair<ll,ll>> v;
    for(ll n=1;n*(n-1)*(2*n-1)/6-n*n*(n-1)/2<=a;n++){
        ll m=a-(n*(n-1)*(2*n-1)/6-n*n*(n-1)/2);
        if(m%(n*(n+1)/2)==0&&m/(n*(n+1)/2)>=n){
            v.pb(mp(n,m/(n*(n+1)/2)));
        }
    }
    printf("%d\n",2*v.size()-(int)(v.back().x==v.back().y));
    For(i,v.size()){
        printf("%I64d %I64d\n",v[i].x,v[i].y);
    }
    for(int i=v.size()-1-(int)(v.back().x==v.back().y);i>=0;i--){
        printf("%I64d %I64d\n",v[i].y,v[i].x);
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