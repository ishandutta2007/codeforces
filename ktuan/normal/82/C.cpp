#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <cstdlib>
using namespace std;

#define Rep(i,n) for(int i=0;i<(n);++i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Ford(i,a,b) for(int i=(a);i>=(b);--i)
#define fi first
#define se second
#define pb push_back
#define MP make_pair

typedef pair<int,int> PII;
typedef vector<int> VI;

int n;
map<int,int> valtoid;
VI ds[2][5050];
vector<PII> ke[5050];
int F[5050], C[5050];
int out[5050];

void dfs(int i, int fi) {
    Rep(k,ke[i].size()) {
        int j = ke[i][k].fi;
        int c = ke[i][k].se;
        if(j != fi) {
            F[j] = i; C[j] = c;
            dfs(j, i);  
        }   
    }
}

int main() {
    scanf("%d", &n);
    For(i,1,n) {
        int x;
        scanf("%d", &x);    
        valtoid[x] = i;
        ds[0][i].pb(x);
    }
    Rep(i,n-1) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        ke[u].pb(MP(v,c));
        ke[v].pb(MP(u,c));  
    }
    dfs( 1, -1);
    int cur = 0;
    int time = 0;
    while(ds[cur][1].size() < n) {
        ++time;
        int next = 1 - cur;
        For(i,1,n) sort(ds[cur][i].begin(),ds[cur][i].end());
        For(i,1,n) ds[next][i].clear();
        For(i,2,n) {
            for(int j=0;j<C[i] && j<ds[cur][i].size();++j) {
                ds[next][F[i]].pb(ds[cur][i][j]);
                if(F[i] == 1) out[valtoid[ds[cur][i][j]]] = time;
            }
        }
        For(i,1,n) {
            for(int j=C[i];j<ds[cur][i].size();++j)
                ds[next][i].pb(ds[cur][i][j]);  
        }
        cur = next;
    }
    For(i,1,n) printf("%d ", out[i]);
    printf("\n");
    return 0;
}