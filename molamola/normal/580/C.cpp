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

int n, m, ans;
vector <int> E[100010];
int cat[100010];
int d[100010], e[100010];

void dfs(int x,int fa){
    if(cat[x])d[x] = d[fa] + 1;
    else d[x] = 0;
    e[x] = max(d[x], e[fa]);
    int t = 0;
    for(auto u : E[x]){
        if(u != fa)t = 1, dfs(u, x);
    }
    if(t == 0 && e[x] <= m)ans++;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)scanf("%d", cat + 1 + i);
    for(int i=1;i<n;i++){
        int x, y;
        scanf("%d%d",&x,&y);
        E[x].pb(y), E[y].pb(x);
    }
    dfs(1, 0);
    printf("%d", ans);
    return 0;
}