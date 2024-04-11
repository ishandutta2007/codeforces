#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <map>
#include <time.h>
#include <string>
#include <algorithm>
#include <queue>
#include <assert.h>
#include <math.h>
#include <complex>

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
const int mod=123456789;
const ll LONGINF=4e18;
const double eps=1e-9;
const double PI=3.1415926535897932384626433832795;

int g[444][444],d[444];

void solve(){
    int n,m,a,b;
    scanf("%d%d",&n,&m);
    For(i,n){
        For(j,n){
            g[i][j]=0;
        }
    }
    For(i,m){
        scanf("%d%d",&a,&b);
        a--;
        b--;
        g[a][b]=g[b][a]=1;
    }
    queue<int> q;
    int edge=g[0][n-1]^1;
    For(i,n) d[i]=INF;
    d[0]=0;
    q.push(0);
    while(!q.empty()){
        a=q.front();
        q.pop();
        For(i,n){
            if(g[a][i]==edge&&d[i]==INF){
                d[i]=d[a]+1;
                q.push(i);
            }
        }
    }
    if(d[n-1]==INF) d[n-1]=-1;
    printf("%d",d[n-1]);


}

int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef _DEBUG
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    solve();
    return 0;
}