#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <map>
#include <time.h>
#include <string>
#include <algorithm>
#include <queue>
#include <assert.h>

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

int g[4040][4040],d[4040];

void solve(int n){
    int m,a,b;
    vector<pair<int,int>> v;
    scanf("%d",&m);
    For(i,m){
        scanf("%d%d",&a,&b);
        a--;
        b--;
        g[a][b]=g[b][a]=1;
        d[a]++;
        d[b]++;
        v.pb(mp(a,b));
    }
    For(i,n){
        d[i]-=2;
    }
    int ans=INF;
    For(i,m){
        For(j,n){
            if(j==v[i].x||j==v[i].y) continue;
            if(g[v[i].x][j]==1&&g[v[i].y][j]==1){
                ans=min(ans,d[v[i].x]+d[v[i].y]+d[j]);
            }
        }
    }
    if(ans==INF){
        ans=-1;
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
    string s;
    while(scanf("%d",&n)==1) solve(n);



    return 0;
}