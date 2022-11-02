#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <map>
#include <time.h>
#include <string>
#include <algorithm>
#include <queue>
#include <assert.h>
#include <math.h>
  
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
const int mod=1e9+7;
const ll LONGINF=4e18;
const double eps=1e-9;
const double PI=3.1415926535897932384626433832795;
 
void solve(int n){
    int d,a,b;
    ll t,ans=-INF,m;
    vector<pair<int,int>> v;
    scanf("%d",&d);
    For(i,n){
        scanf("%d%d",&a,&b);
        v.pb(mp(a,b));
    }
    sort(all(v));
    int l=0,r=0;
    t=0;
    while(r<n){
        t+=v[r].y;
        while(v[l].x<=v[r].x-d){
            t-=v[l].y;
            l++;
        }
        r++;
        ans=max(ans,t);
    }
    printf("%I64d",ans);
}
  
int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef _DEBUG
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    int n;
    string s;
    scanf("%d",&n);
    solve(n);
    return 0;
}