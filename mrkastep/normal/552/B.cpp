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

void solve(int n){
    int t=1e9;
    int tmp=10;
    ll ans=0;
    while(t>0){
        if(n>=t){
            ans+=(ll)tmp*(n%t+1)+(ll)(n/t-1)*tmp*t;
            t/=10;
            tmp--;
            break;
        }
        t/=10;
        tmp--;
    }
    int tt=tmp;
    For(i,tt){
        ans+=(ll)9*tmp*t;
        tmp--;
        t/=10;
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
    ll a;
    string s;
    while(scanf("%d",&n)==1) solve(n);

    return 0;
}