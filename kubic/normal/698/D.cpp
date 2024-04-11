#include <bits/stdc++.h>
using namespace std;
#define N 1005
#define ll long long
#define set(a,vl) memset(a,vl,sizeof(a))
int n,m,nw,gr,ans,ord[N],vs[N];vector<int> e[8][N];bool tg[N];
struct Point
{
	ll x,y;
	Point(ll _x=0,ll _y=0) {x=_x;y=_y;}
	Point operator + (Point t) const {return Point(x+t.x,y+t.y);}
	Point operator - (Point t) const {return Point(x-t.x,y-t.y);}
}a[N],b[N];
ll dotMul(Point x,Point y) {return x.x*y.x+x.y*y.y;}
ll crsMul(Point x,Point y) {return x.x*y.y-x.y*y.x;}
bool dfs(int u)
{
	if(vs[u]==gr) return 1;if(nw>m) return 0;int t=ord[nw++];
	for(int i=0;i<e[t][u].size();++i) if(!dfs(e[t][u][i])) return 0;
	vs[u]=gr;return 1;
}
int main()
{
	scanf("%d %d",&m,&n);for(int i=1;i<=m;++i) ord[i]=i;
	for(int i=1;i<=m;++i) scanf("%lld %lld",&a[i].x,&a[i].y);
	for(int i=1;i<=n;++i) scanf("%lld %lld",&b[i].x,&b[i].y);
	for(int i=1;i<=m;++i) for(int j=1;j<=n;++j) for(int k=1;k<=n;++k)
		if(j!=k && !crsMul(b[j]-a[i],b[k]-a[i]) && dotMul(a[i]-b[k],b[j]-b[k])<0)
			e[i][j].push_back(k);
	while(1)
	{
		for(int i=1;i<=n;++i) nw=1,++gr,tg[i]|=dfs(i);
		if(!next_permutation(ord+1,ord+m+1)) break;
	}for(int i=1;i<=n;++i) ans+=tg[i];printf("%d\n",ans);return 0;
}