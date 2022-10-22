#include <bits/stdc++.h>
using namespace std;
#define N 205
int n,m,ans,fa[N];bool fl,vs[N];
int rt(int x) {return x==fa[x]?x:fa[x]=rt(fa[x]);}
void merge(int x,int y) {x=rt(x);y=rt(y);if(x!=y) fa[x]=y,fl=1;}
int main()
{
    scanf("%d %d",&n,&m);for(int i=1;i<=n+m;++i) fa[i]=i;
    for(int i=1,cntT,t;i<=n;++i) {scanf("%d",&cntT);for(int j=1;j<=cntT;++j) scanf("%d",&t),merge(i,t+n);}
    for(int i=1,t;i<=n;++i) {t=rt(i);if(!vs[t]) vs[t]=1,++ans;}if(!fl) ++ans;printf("%d\n",ans-1);
}