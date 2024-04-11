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

ll a[300300];

void solve(int n){
    int s[63],k,d;
    ll t=1;
    ll ans=0;
    For(i,63) s[i]=0;
    scanf("%d%d",&k,&d);
    For(i,k) t*=d;
    For(i,n){
        scanf("%I64d",&a[i]);
        For(j,63) if(a[i]&(1ll<<j)) s[j]++;
    }
    For(i,n){
        if(a[i]==0) continue;
        ll tmp=0;
        For(j,63) if(a[i]&(1ll<<j)) s[j]--;
        t*=a[i];
        For(j,63){
            if(t&(1ll<<j)) s[j]++;
            if(s[j]>0) tmp|=(1ll<<j);
        }
        ans=max(ans,tmp);
        For(j,63) if(t&(1ll<<j)) s[j]--;
        t/=a[i];
        For(j,63) if(a[i]&(1ll<<j)) s[j]++;
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
    while(scanf("%d",&n)==1) solve(n);
    return 0;
}