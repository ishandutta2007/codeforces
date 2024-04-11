#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <map>
#include <time.h>
#include <algorithm>

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

void solve(ll a){
    ll b;
    bool g=false;
    vector<int> s;
    while(a>0){
        s.pb(a%10);
        a/=10;
    }
    for(b=s.size()-1;b>-1;b--){
        if(s[b]!=0&&s[b]!=9){
            g=true;
        }
        if(g) s[b]=min(s[b],9-s[b]); 
        if(s[b]==9){
            g=true;
        }
    }
    while(s.size()>0&&s.back()==0){
        s.pop_back();
    }
    while(s.size()!=0){
        printf("%d",s.back());
        s.pop_back();
    }
    printf("\n");

    


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
    while(scanf("%I64d",&a)==1) solve(a);

    return 0;
}