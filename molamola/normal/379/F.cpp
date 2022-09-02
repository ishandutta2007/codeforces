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

int st[1000010],en[2000010],next[2000010];
int up[1000010][20],q;
int n;
bool check[1000010];
int dep[1000010];

void addedge(int s,int d,int c){next[c]=st[s],st[s]=c,en[c]=d;}
void add(int s,int d,int c){addedge(s,d,c),addedge(d,s,c+1);}

void dfs(int x)
{
    check[x]=1;
    for(int i=st[x];i;i=next[i]){
        if(check[en[i]])continue;
        up[en[i]][0]=x;
        for(int j=1;j<20;j++)up[en[i]][j]=up[up[en[i]][j-1]][j-1];
        dep[en[i]]=dep[x]+1;
        dfs(en[i]);
    }
    check[x]=0;
}

int lca(int x,int y)
{
    if(dep[x]<dep[y])x^=y^=x^=y;
    int a = dep[x]-dep[y];
    int i;
    for(i=0;i<20;i++)if(a&1<<i)x=up[x][i];
    for(i=19;i>=0;i--){
        if(up[x][i]!=up[y][i])x=up[x][i],y=up[y][i];
    }
    return up[x][0];
}

int get(int a,int b)
{
    int l = lca(a,b);
    return dep[a]+dep[b]-dep[l]*2;
}

int main()
{
    int i;
    add(1,2,2);
    add(1,3,4);
    add(1,4,6);
    scanf("%d",&q);
    for(i=0;i<q;i++){
        int x;
        scanf("%d",&x);
        add(x,(i<<1)+5,(i<<2)+8);
        add(x,(i<<1)+6,(i<<2)+10);
    }
    n=(q<<1)+4;
    dfs(1);
    int d1=2,d2=3,now=2;
    lca(12,14);
    for(i=5;i<=n;i++){
        int l1=get(i,d1);
        int l2=get(i,d2);
        if(l1>now)now++,d2=i;
        else if(l2>now)now++,d1=i;
        if(i%2==0)printf("%d\n",now);
    }
    return 0;
}