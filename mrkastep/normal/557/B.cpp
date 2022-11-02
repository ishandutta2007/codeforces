#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <map>
#include <time.h>
#include <string>
#include <algorithm>

using namespace std;

#define For(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define ll long long int
#define all(v) (v).begin(),(v).end()

const int INF=2e9;
const int mod=1e9+7;
const ll LONGINF=4e18;
const double eps=1e-9;
const double PI=3.1415926535897932384626433832795;

typedef pair<double,double> point;

void solve(int n){
    vector<int> v;
    int s,a;
    scanf("%d",&s);
    For(i,2*n){
        scanf("%d",&a);
        v.pb(a);
    }
    sort(all(v));
    double ans=min((double)v[0],(double)v[n]/2)*3*n;
    ans=min(ans,(double)s);
    printf("%.1lf",ans);


}

int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef _DEBUG
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    int n,cnt;
    ll a;
    string t;
    char c[5555];
    while(scanf("%d",&n)==1) solve(n);
    return 0;
}