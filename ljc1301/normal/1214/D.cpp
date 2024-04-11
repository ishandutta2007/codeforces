#include <bits/stdc++.h>
using namespace std;
const int maxn=1000005;
char s[maxn];
bool vis[maxn];
int n,m;
bool dfs(int x,int y)
{
    if(!x && !y) return 1;
    if(s[x*m+y]=='#' || vis[x*m+y]) return 0;
    bool res=0;
    vis[x*m+y]=1;
    if(x && dfs(x-1,y)) res=1;
    if(y && dfs(x,y-1)) res=1;
    return res;
}
int dfs1(int xa,int ya,int xb,int yb)
{
    solve:
    if(xa==n-1 && ya==m-1) return 2;
    if((xa || ya) && xa==xb && ya==yb) return 1;
    if(xa<n-1 && s[(xa+1)*m+ya]=='.' && vis[(xa+1)*m+ya]) xa++;
    else ya++;
    if(yb<m-1 && s[xb*m+yb+1]=='.' && vis[xb*m+yb+1]) yb++;
    else xb++;
    goto solve;
}
int main()
{
    int i;
    scanf("%d%d",&n,&m);
    for(i=0;i<n*m;i+=m)
        scanf("%s",s+i);
    for(i=0;i<n*m;i++) vis[i]=0;
    if(!dfs(n-1,m-1)) printf("0\n");
    else printf("%d\n",dfs1(0,0,0,0));
    return 0;
}