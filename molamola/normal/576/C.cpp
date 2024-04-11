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
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<int, int> Pi;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()

int x[1000010], y[1000010];
int n;
vector <int> ans;

void dfs(vector <int> &v, int L, int dx, int dy){
    if(sz(v) == 1){ans.pb(v[0]);return;}
    vector <int> t[4];
    for(auto u : v){
        if(x[u]-dx < L/2 && y[u]-dy < L/2)t[0].pb(u);
        else if(x[u]-dx < L/2 && y[u]-dy >= L/2)t[1].pb(u);
        else if(x[u]-dx >= L/2 && y[u]-dy < L/2)t[2].pb(u);
        else t[3].pb(u);
    }
    int xx[4] = {0, 0, L/2, L/2};
    int yy[4] = {0, L/2, 0, L/2};
    for(int i=0;i<4;i++){
        if(sz(t[i]) > 0)dfs(t[i], L/2, dx + xx[i], dy + yy[i]);
    }
}

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d%d",x+i,y+i);
    vector <int> v;
    for(int i=0;i<n;i++)v.pb(i);
    dfs(v, 1<<20, 0, 0);
    for(int i=0;i<sz(ans);i++)printf("%d ", ans[i]+1);
    return 0;
}