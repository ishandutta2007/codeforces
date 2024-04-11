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

struct point{
    int x, y, c;
}p[200020];

bool compx(const point &a, const point &b){
    return a.x != b.x ? a.x < b.x : a.y < b.y;
}
bool compy(const point &a, const point &b){
    return a.y != b.y ? a.y < b.y : a.x < b.x;
}

int n;
vector <int> E[200020];
int ans[200020];
int chk[200020];
int cx[200020], cy[200020];

void dfs(int x,int t){
    chk[x] = 1;
    ans[x] = t;
    for(int i : E[x]){
        if(!chk[i]){
            dfs(i, 1-t);
        }
    }
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d%d",&p[i].x,&p[i].y), p[i].c = i;
    sort(p, p+n, compx);
    for(int i=1;i<n;i++){
        if(!cx[p[i].x] && p[i].x == p[i-1].x)E[p[i].c].pb(p[i-1].c), E[p[i-1].c].pb(p[i].c), cx[p[i].x] = 1;
        else cx[p[i].x] = 0;
    }
    sort(p, p+n, compy);
    for(int i=1;i<n;i++){
        if(!cy[p[i].y] && p[i].y == p[i-1].y)E[p[i].c].pb(p[i-1].c), E[p[i-1].c].pb(p[i].c), cy[p[i].y] = 1;
        else cy[p[i].y] = 0;
    }
    for(int i=0;i<n;i++)if(!chk[i])dfs(i, 0);
    for(int i=0;i<n;i++)printf("%c", ans[i] ? 'r' : 'b');
    return 0;
}