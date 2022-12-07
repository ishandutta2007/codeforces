#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
using namespace std;
const int MAXN=100010;
int n,m,ans;
int d[MAXN],h[MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) scanf("%d%d",&d[i],&h[i]),ans=max(ans,h[i]);
    ans=max(ans,h[1]+d[1]-1);
    ans=max(ans,h[m]+n-d[m]);
    for(int i=1;i<m;i++)
    {
        if(abs(d[i]-d[i+1])<abs(h[i]-h[i+1])) {puts("IMPOSSIBLE");return 0;}
        int x=d[i+1]-d[i];
        x-=abs(h[i]-h[i+1]);
        ans=max(ans,max(h[i],h[i+1])+(x>>1));
    }
    printf("%d\n",ans);
    return 0;
}