#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
using namespace std;

#define X first
#define Y second
typedef pair<int,int> P;

const int MV = 100010;
const int ME = MV<<1;
const int LMV = 18;
const int inf = 1e8;

int st[MV], en[ME], next[ME];
int N, dep[MV], up[MV][LMV], par[MV], dis[MV];
int down[MV];
bool check[MV];
bool cut[ME];

void addedge(int s,int d,int c)
{
    next[c]=st[s];
    st[s]=c;
    en[c]=d;
}

void dfs(int x,int p)
{
    check[x]=down[x]=1;
    for(int i=st[x];i;i=next[i]){
        if(!check[en[i]] && !cut[i])up[en[i]][p] = up[x][p]+1, dfs(en[i],p), down[x]+=down[en[i]];
    }check[x]=0;
}

int find_mid(int x)
{
    int u = down[x]>>1, i;
    for(;;){
        for(i=st[x];i;i=next[i]){
            if(cut[i] || down[x]<down[en[i]])continue;
            if(down[en[i]]>u){x=en[i];break;}
        }
        if(!i)return x;
    }
}

void solve(int x,int pa)
{
    int r = find_mid(x);
    dep[r] = dep[pa]+1;
    par[r] = pa;
    dfs(r,dep[r]);
    for(int i=st[r];i;i=next[i]){
        if(cut[i])continue;
        cut[i] = cut[i^1] = 1;
        solve(en[i],r);
    }
}

void update(int x)
{
    for(int t=x;t;t=par[t])dis[t] = min(dis[t],up[x][dep[t]]);
}

int read(int x)
{
    int ret=inf;
    for(int t=x;t;t=par[t])ret=min(ret,dis[t]+up[x][dep[t]]);
    return ret;
}

void pre()
{
    dfs(1,0);
    solve(1,0);
    for(int i=1;i<=N;i++)dis[i]=inf;
    update(1);
}

int getInt()
{
    int t=0;
    char x=getchar();
    while(isdigit(x)){
        t=(t<<1)+(t<<3)+x-48;
        x=getchar();
    }
    return t;
}

int main()
{
//    freopen("input.txt","r",stdin);
    N=getInt();
    int q=getInt(), i;
    for(i=1;i<N;i++){
        int x=getInt(),y=getInt();
        addedge(x,y,2*i);
        addedge(y,x,2*i+1);
    }
    pre();
    while(q--){
        int cmd=getInt(),x=getInt();
        if(cmd==1)update(x);
        else printf("%d\n",read(x));
    }
    return 0;
}