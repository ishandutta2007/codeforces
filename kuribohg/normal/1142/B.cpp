#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#define next next2
using namespace std;
const int MAXN=200010;
int n,m,Q,p[MAXN],a[MAXN],next[MAXN],cur[MAXN],r[MAXN],anc[MAXN][22];
vector<int> v[MAXN];
int main()
{
    scanf("%d%d%d",&n,&m,&Q);
    for(int i=1;i<=n;i++) scanf("%d",&p[i]);
    for(int i=1;i<=m;i++) scanf("%d",&a[i]);
    for(int i=1;i<=m;i++) v[a[i]].push_back(i);
    for(int i=1;i<n;i++) next[p[i]]=p[i+1];
    next[p[n]]=p[1];
    for(int i=1;i<=m;i++)
    {
        int o=next[a[i]];
        while(cur[o]<v[o].size()&&v[o][cur[o]]<i) cur[o]++;
        if(cur[o]<v[o].size()) r[i]=v[o][cur[o]];
    }
    for(int i=1;i<=m;i++) anc[i][0]=r[i];
    for(int i=1;i<=20;i++)
        for(int j=1;j<=m;j++)
            anc[j][i]=anc[anc[j][i-1]][i-1];
    for(int i=1;i<=m;i++)
    {
        int x=i;
        for(int j=20;j>=0;j--)
            if((n-1)&(1<<j)) x=anc[x][j];
        if(x!=0) r[i]=x;
        else r[i]=m+1;
    }
    for(int i=m-1;i>=1;i--) r[i]=min(r[i],r[i+1]);
    for(int i=1,x,y;i<=Q;i++)
    {
        scanf("%d%d",&x,&y);
        if(r[x]>y) putchar('0');
        else putchar('1');
    }
    puts("");
    return 0;
}