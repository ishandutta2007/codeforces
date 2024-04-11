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

vector<int> g[100100];
int d[100100],ind[100100];

void solve(){
    int n,m,a,b;
    scanf("%d%d",&n,&m);
    For(i,m){
        scanf("%d%d",&a,&b);
        a--;
        b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    For(i,n){
        d[i]=1;
    }
    For(i,n){
        For(j,g[i].size()){
            if(g[i][j]<i) d[i]=max(d[i],d[g[i][j]]+1);
        }
    }
    ll ans=0;
    For(i,n){
        ans=max(ans,(ll)d[i]*g[i].size());
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