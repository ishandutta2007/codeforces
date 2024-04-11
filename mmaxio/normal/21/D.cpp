#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(v) (int(v.size()))
#define pch putchar
#define gch getchar()
#define FORD(i,a,b) for (int i=(a); i<=(b); i++)
#define FORP(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,n) for (int i=0; i<(n); i++)
#define clean(v) memset(v,0,sizeof(v))

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

template<typename T> T sqr(const T& c) {return c*c;} 

typedef long long ll;
typedef double lf;

const int inf = 1000000000;

int g[15][15];
bool was[15];
int deg[15];

vector<int> odd;

int dp[1<<14], n, m;

void DFS(int v) {
    was[v] = 1;
    REP(i,n) if (!was[i] && g[v][i]!=inf) DFS(i);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    scanf("%d%d",&n,&m); REP(i,n) REP(j,n) g[i][j] = i!=j?inf:0;
    int ans = 0;
    REP(i,m) {
        int v1, v2, cost;
        scanf("%d%d%d",&v1,&v2,&cost);
        v1--, v2--;
        deg[v1]++, deg[v2]++; ans += cost;
        g[v2][v1] = g[v1][v2] = min(g[v1][v2],cost);
    }
    
    DFS(0);
    REP(i,n) if (!was[i] && deg[i]>0) {puts("-1"); return 0;}

    REP(k,n) REP(i,n) REP(j,n) g[i][j] = min(g[i][j],g[i][k]+g[k][j]);
    
    REP(i,n) if (deg[i]&1) odd.pb(i);
    
    int k = sz(odd);

    //REP(i,k) cerr << odd[i] << ' ';
    //cerr << ans;

    //REP(i,n) {REP(j,n) cerr << g[i][j] << ' '; cerr << '\n';}

    dp[0] = 0;
    FORD(m,1,(1<<k)-1) {
        int cnt = 0;
        REP(i,k) if (m&(1<<i)) cnt++;
        if (cnt&1) continue;
        dp[m] = inf;
        int v1, v2, p1, p2;
        REP(i,k) if (m&(1<<i)) {
            v1 = odd[i], p1 = i; break;
        }
        FORD(i,p1,k-1) if (m&(1<<i)) {
            v2 = odd[i], p2 = i;
            dp[m] = min(dp[m],dp[m^(1<<p1)^(1<<p2)]+g[v1][v2]);
        }
    }
    
    printf("%d",ans+dp[(1<<k)-1]);

}