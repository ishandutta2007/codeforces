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

int t[111][111];

void solve(int n){
    For(i,111){
        For(j,111){
            t[i][j]=0;
        }
    }
    For(c,n){
        int x1,x2,y1,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        FOR(i,x1,x2+1){
            FOR(j,y1,y2+1){
                t[i][j]++;
            }
        }
    }
    int ans=0;
    For(i,111){
        For(j,111){
            ans+=t[i][j];
        }
    }
    printf("%d",ans);




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