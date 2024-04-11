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

bool prime(int a){
    FOR(i,2,a) if(a%i==0) return false;
    return true;
}

void solve(int n){
    vector<int> ans;
    FOR(i,2,n+1){
        if(prime(i)){
            int t=i;
            while(t<=n){
                ans.pb(t);
                t*=i;
            }
        }
    }
    printf("%d\n",ans.size());
    For(i,ans.size()){
        printf("%d ",ans[i]);
    }



}

int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef _DEBUG
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    int n;
    while(scanf("%d",&n)==1) solve(n);
    return 0;
}