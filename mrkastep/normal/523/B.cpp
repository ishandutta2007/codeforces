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

ll sb[200200];
int a[200200];




void solve(int n){
    int i,j,m,t,p,pos=0;
    double mean=0,c,real;
    scanf("%d",&t);
    scanf("%lf",&c);
    For(i,n){
        scanf("%d",&a[i]);
        sb[i]=a[i];
        if(i>0){
            sb[i]+=sb[i-1];
        }
    }
    scanf("%d",&m);
    For(i,m){
        scanf("%d",&p);
        while(pos<p){
            mean=(mean+(double)a[pos]/t)/c;
            pos++;
        }
        real=sb[p-1]-((p-t-1>-1)?sb[p-t-1]:0);
        real/=t;
        printf("%.6lf %.6lf %.6lf\n",real,mean,abs(real-mean)/real);
        
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