#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <map>
#include <time.h>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

#define For(i,n) for(i=0;i<(n);i++)
#define FOR(i,a,b) for(i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define ll long long int


const int INF=2e9;
const int mod=1e9+7;
const ll LONGINF=4e9;
const double eps=1e-9;

int s(ll a){
    int ans=0;
    while(a>0){
        ans+=a%10;
        a/=10;
    }
    return ans;
}

void solve(int a1){
    ll a=a1,b,c,t,pr=0,sm;
    int i,j;
    vector<ll> ans;
    scanf("%I64d%I64d",&b,&c);
    i=1;
    while(i<82&&pr<1e9){
        t=i;
        For(j,a-1){
            t*=i;
        }
        if(b*t+c<1000000000&&s(b*t+c)==i){
            ans.pb(b*t+c);
        }
        pr=b*t+c;
        i++;
    }
    printf("%d\n",ans.size());
    For(i,ans.size()){
        printf("%I64d ",ans[i]);
    }


#ifdef HOME
    printf("\n\nTime in ms: %.0lf\n",clock()/CLOCKS_PER_SEC*1000);
#endif
}


int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef HOME
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    int n;
    ll a;
    char c[200200];
    string s;
    while(scanf("%d",&n)==1) solve(n);

    return 0;
}