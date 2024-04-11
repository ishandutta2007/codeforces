#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <map>
#include <time.h>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

#define For(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(v) (v).begin(),(v).end()

typedef pair<int,int> point;
typedef long long int ll;

const int INF=2e9;
const int mod=1e9+7;
const ll LONGINF=4e18;
const double eps=1e-9;

void solve(int n){
    vector<int> a;
    vector<double> ans;
    int c,b,mn=INF,mx=-INF,s=0;
    scanf("%d",&b);
    For(i,n){
        scanf("%d",&c);
        a.pb(c);
        mx=max(mx,c);
        mn=min(mn,c);
    }
    For(i,n){
        ans.pb(mx-a[i]);
        s+=mx-a[i];
    }
    if(s>b){
        printf("-1");
        return;
    }
    For(i,n){
        ans[i]+=(double)(b-s)/n;
    }
    For(i,n){
        printf("%.10lf\n",ans[i]);
    }






}

int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef HOME
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    int n,k;
    ll a;
    string s;
    while(scanf("%d",&n)==1) solve(n);


    return 0;
}