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

vector<vector<int>> g;

int ans=0,c[100100],m,st[100100];

void dfs(int v,int s){
    st[v]=0;
    if((s+c[v])*c[v]>m) return;
    if(g[v].size()==1&&v!=0){
        ans++;
    }
    For(i,g[v].size()){
        if(st[g[v][i]]==1){
            dfs(g[v][i],(s+c[v])*c[v]);
        }
    }
}

void solve(int n){
    g.resize(n);
    int a,b;
    st[n-1]=1;
    scanf("%d",&m);
    For(i,n){
        scanf("%d",&c[i]);
    }
    For(i,n-1){
        st[i]=1;
        scanf("%d%d",&a,&b);
        a--;
        b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(0,0);
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
    scanf("%d",&n);
    solve(n);
    return 0;
}