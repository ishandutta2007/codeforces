#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

#define rep0(i,x) for(int i=0;i<x;i++)
#define rep1(i,x) for(int i=1;i<=x;i++)
#define rep(i,x,y) for(int i=x;i<y;i++)
#define pb(x) push_back(x)

typedef pair<int,int> Pi;
typedef long long ll;

int n, m;
vector <int> D[500050], xr[500050];
vector <int> E[500050];
int p[500050];
int S[500050], R[500050], co;
char ch[500050];

bool chk(int x){
    //printf("%d\n",x);
    if(x == 0)return true;
    if(x == (x & -x))return true;
    return false;
}

void dfs(int x, int d){
    S[x] = ++co;
    D[d].pb(co);
    xr[d].pb(1 << (ch[x] - 'a'));
    for(int i=0;i<(int)E[x].size();i++){
        dfs(E[x][i], d+1);
    }
    R[x] = co;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=2;i<=n;i++)scanf("%d",p+i), E[p[i]].push_back(i);
    scanf("%s", ch+1);
    dfs(1, 1);
    for(int i=1;i<=n;i++)for(int j=1;j<(int)xr[i].size();j++)xr[i][j] ^= xr[i][j-1];
    while(m--){
        int x, y;
        scanf("%d%d",&x,&y);
        int ts = lower_bound(D[y].begin(), D[y].end(), S[x]) - D[y].begin();
        int te = upper_bound(D[y].begin(), D[y].end(), R[x]) - D[y].begin() - 1;
        if(te < 0 || chk(ts == 0 ? xr[y][te] : (xr[y][te] ^ xr[y][ts-1])))puts("Yes");
        else puts("No");
    }
    return 0;
}