#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<ctype.h>
using namespace std;

#define X first
#define Y second
typedef long long ll;
typedef pair<int,int> Pi;

int S[200020], now, D[200020], inv[200020];
int st[200020], en[400040], next[400040];
int n, m;
int inp[200020];
int wh[200020];
int dep[200020];
int T[2][200020];

void addedge(int s,int e,int c){next[c]=st[s],st[s]=c,en[c]=e;}

void update1(int x,int item,int m)
{
    for(int i=x;i;i-=(i&-i))T[m][i] += item;
}

void update(int s,int e,int item,int m){update1(s-1,-item,m), update1(e,item,m);}

int read(int s,int m)
{
    if(s==0)return 0;
    int ret = 0;
    for(int i=s;i<=n;i+=(i&-i))ret += T[m][i];
    return ret;
}

bool chk[200020];

void dfs(int x)
{
    S[x] = now;
    chk[x] = 1;
    for(int i=st[x];i;i=next[i]){
        if(!chk[en[i]]){
            dep[en[i]] = dep[x] + 1;
            dfs(en[i]);
        }
    }
    chk[x] = 0;
    D[x] = ++now;
}

int main()
{
    scanf("%d%d",&n,&m);
    int i;
    for(i=1;i<=n;i++)scanf("%d",inp+i);
    for(i=1;i<n;i++){
        int x, y;
        scanf("%d%d",&x,&y);
        addedge(x, y, i<<1);
        addedge(y, x, i<<1|1);
    }
    dfs(1);
    for(i=1;i<=n;i++)wh[i] = (dep[i]&1);
    for(i=1;i<=m;i++){
        int x, y;
        scanf("%d%d",&x,&y);
        if(x==2){
            int t = wh[y];
            printf("%d\n",read(D[y],t) + inp[y]);
        }
        else{
            int v;
            scanf("%d",&v);
            int t = wh[y];
            if(t==0)update(S[y]+1,D[y],v,0), update(S[y]+1,D[y],-v,1);
            else update(S[y]+1,D[y],v,1), update(S[y]+1,D[y],-v,0);
        }
    }
    return 0;
}