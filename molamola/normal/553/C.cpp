#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<int, int> Pi;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()

const ll MOD = 1e9 + 7;
int n, m;
int p[100010];
ll pw[100010];
int inp[100010][3];
vector <int> E[100010];
int chk[100010];
int col[100010];

int find(int x){
    return x == p[x] ? x : p[x] = find(p[x]);
}

bool dfs(int x,int color){
    col[x] = color;
    chk[x] = 1;
    for(auto u : E[x]){
        if(col[x] == col[u])return false;
        if(!chk[u] && !dfs(u, 3 - color))return false;
    }
    return true;
}

int main() {
    pw[0] = 1;
    for(int i=1;i<=100005;i++)pw[i] = 2 * pw[i-1] % MOD;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)p[i] = i;
    for(int i=0;i<m;i++){
        scanf("%d%d%d",inp[i],inp[i]+1,inp[i]+2);
    }
    for(int i=0;i<m;i++){
        if(inp[i][2] == 1){
            int x = find(inp[i][0]), y = find(inp[i][1]);
            p[x] = y;
        }
    }
    for(int i=0;i<m;i++){
        if(inp[i][2] == 0){
            int x = find(inp[i][0]), y = find(inp[i][1]);
            E[x].pb(y), E[y].pb(x);
        }
    }
    int c = 0;
    for(int i=1;i<=n;i++){
        if(i == find(i) && chk[i] == 0){
            if(!dfs(i, 1)){printf("0");return 0;}
            c++;
        }
    }
    printf("%lld\n", pw[c-1]);
    return 0;
}