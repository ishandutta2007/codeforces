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
#include <cmath>
#include <complex>
#include <unordered_map>
#include <stack>
#include <set>

#pragma warning(disable:4996)

using namespace std;

#define For(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define x first
#define y second

typedef long long int ll;
typedef vector<ll> lll;
typedef complex<double> point;
//typedef pair<double,double> point;

const int INF=2e9;
const int mod=1e9+7;
const ll LONGINF=4e18;
const double eps=1e-9;
const double PI=3.1415926535897932384626433832795;

map<int,int> m;
vector<pair<int,int>> v;

ll binpw(ll a,ll d){
    ll ans=1;
    for(int i=60;i>=0;i--){
        ans*=ans;
        ans%=mod;
        if(d&(1ll<<i)) ans*=a;
        ans%=mod;
    }
    return ans;
}

void solve(){
    int n,p;
    bool bad=true;
    ll d=1,prod=1,r2=(mod+1)/2;
    scanf("%d",&n);
    For(i,n){
        scanf("%d",&p);
        m[p]++;
    }
    for(auto it:m) v.pb(it);
    For(i,v.size()){
        if(bad&&v[i].y%2==1){
            d*=(v[i].y+1)/2;
            bad=false;
        }
        else{
            d*=(v[i].y+1);
        }
        d%=mod-1;
        prod*=v[i].x;
        prod%=mod;
    }
    ll ans=1;
    For(i,v.size()){
        if(bad){
            ans*=binpw(v[i].x,(d*v[i].y/2)%(mod-1));
        }
        else{
            ans*=binpw(v[i].x,(d*v[i].y)%(mod-1));
        }
        ans%=mod;
    }
    printf("%I64d",ans);
}

int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef _DEBUG
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
    //#else
    //  freopen("a.in","rt",stdin);
    //  freopen("a.out","wt",stdout);
#endif
    solve();
    return 0;
}