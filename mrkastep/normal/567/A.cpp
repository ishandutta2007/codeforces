#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <map>
#include <time.h>
#include <string>
#include <algorithm>
#include <queue>
#include <assert.h>

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

typedef pair<double,double> point;

void solve(int n){
    vector<int> v;
    int a;
    For(i,n){
        scanf("%d",&a);
        v.pb(a);
    }
    For(i,n){
        if(i==0){
            printf("%d %d\n",v[1]-v[0],v[n-1]-v[0]);
            continue;
        }
        if(i==n-1){
            printf("%d %d\n",v[n-1]-v[n-2],v[n-1]-v[0]);
            continue;
        }
        printf("%d %d\n",min(v[i]-v[i-1],v[i+1]-v[i]),max(v[i]-v[0],v[n-1]-v[i]));
    }








}

int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef _DEBUG
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    char c[5555];
    int n;
    while(scanf("%d",&n)==1) solve(n);
    return 0;
}