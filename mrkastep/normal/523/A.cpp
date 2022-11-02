#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <map>
#include <time.h>
#include <string>
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

void solve(int n){
    int m,i,j;
    char c[111];
    string s;
    vector<string> t;
    scanf("%d",&m);
    gets(c);
    For(i,m){
        gets(c);
        s=c;
        t.pb(s);
    }
    For(j,n){
        For(i,m){

            printf("%c",t[i][j]);
            printf("%c",t[i][j]);
        }
        printf("\n");
        For(i,m){
            printf("%c",t[i][j]);
            printf("%c",t[i][j]);
        }
        printf("\n");
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