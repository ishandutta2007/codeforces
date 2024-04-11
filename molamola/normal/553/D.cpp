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

vector <int> E[100010];
int n, m, k;
int fort[100010];
int d[100010];
double now;
vector <int> ans;
vector <int> tmp;
int deg[100010];
int min_degree[100010];
int now_d[100010];
int ck[100010];
int que[100010], *fr, *re;

bool chk(double x){
    memset(ck, 0, sizeof ck);
    for(int i=1;i<=n;i++){
        min_degree[i] = (int)(deg[i] * (x - 1e-15)) + 1;
        now_d[i] = 0;
    }
    for(int i=1;i<=n;i++){
        if(fort[i]){ck[i] = 1;continue;}
        for(int u : E[i]){
            if(fort[u])continue;
            now_d[i]++;
        }
    }
    fr = re = que;
    for(int i=1;i<=n;i++){
        if(!fort[i] && now_d[i] < min_degree[i])*fr++ = i, ck[i] = 1;
    }
    while(fr != re){
        int t = *re++;
        for(int u : E[t]){
            if(ck[u])continue;
            now_d[u]--;
            if(now_d[u] < min_degree[u])*fr++ = u, ck[u] = 1;
        }
    }
    tmp.clear();
    for(int i=1;i<=n;i++)if(ck[i] == 0)tmp.pb(i);
    if(sz(tmp) == 0)return false;
    ans.clear();
    for(auto i : tmp)ans.pb(i);
    return true;
}

int main() {
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<k;i++){
        int x; scanf("%d", &x);
        fort[x] = 1;
    }
    for(int i=1;i<=n;i++)if(!fort[i])ans.pb(i);
    for(int i=0;i<m;i++){
        int x, y; scanf("%d%d",&x,&y);
        E[x].pb(y), E[y].pb(x);
    }
    for(int i=1;i<=n;i++)deg[i] = sz(E[i]);
    double low = 0, high = 1, mid;
    while(high - low > 1e-10){
        mid = (low + high) / 2;
        if(chk(mid))low = mid;
        else high = mid;
    }
    //printf("%lf\n", mid);
    printf("%d\n",sz(ans));
    for(auto i : ans)printf("%d ", i);
    return 0;
}