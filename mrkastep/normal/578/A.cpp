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

void solve(int a){
    int b,k;
    double ans=INF,x;
    scanf("%d",&b);
    if(a==b){
        printf("%d",b);
        return;
    }
    if(a<b){
        printf("-1");
        return;
    }
    int l=1,r=INF;
    while(r-l>1){
        int c=(l+r)/2;
        if((double)(a-b)/(2*c)<b) r=c;
        else l=c;
    }
    if((double)(a-b)/(2*l)>=b) ans=min(ans,(double)(a-b)/(2*l));
    l=0,r=INF;
    while(r-l>1){
        int c=(l+r)/2;
        x=((double)(a+b)/(2*(c+1)));
        if(x<b) r=c;
        else l=c;
    }
    x=((double)(a+b)/(2*(l+1)));
    if(x>=b) ans=min(ans,x);
    if(ans==INF){
        printf("-1");
    }
    else{
        printf("%.10lf",ans);
    }


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