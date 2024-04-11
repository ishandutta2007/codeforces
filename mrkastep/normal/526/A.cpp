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
    string s;
    char c[111];
    bool g;
    gets(c);
    gets(c);
    s=c;
    For(i,n){
        FOR(j,1,n){
            g=true;
            For(k,5){
                if(i+j*k>=n||s[i+j*k]!='*') g=false;
            }
            if(g){
                printf("yes");
                return;
            }
        }
    }
    printf("no");





}






int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef HOME
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    int n;
    ll a;
    char c[100100];
    string s;
    while(scanf("%d",&n)==1) solve(n);

    return 0;
}