//
//
#include<bits/stdc++.h>
using namespace std;const double Pi=acos(-1);
struct arr
{
	double x,y,r,ar;int id;
	bool operator<(arr b) const {return r<b.r;}
	bool operator>(arr b) {return (x-b.x)*(x-b.x)+(y-b.y)*(y-b.y)<r*r;}
}a[1005];
struct edge{int to,nxt;}e[1005];int n,et,rt,head[1005];double rs=0,dp[1005][2],s[1005];char v[1005];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void dfs(int x,int dep,int val)
{
	if(dep==2) val*=-1;
	rs+=a[x].ar*val;
	for(int i=head[x];i;i=e[i].nxt) dfs(e[i].to,dep+1,-val);
}
int main()
{
	scanf("%d",&n),rt=n+1;for(int i=1;i<=n;i++) scanf("%lf%lf%lf",&a[i].x,&a[i].y,&a[i].r),a[i].ar=a[i].r*a[i].r,a[i].id=i;
	sort(a+1,a+n+1);for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(a[j]>a[i]) {adde(j,i),v[i]=1;break;}
	for(int i=1;i<=n;i++) if(!v[i]) dfs(i,1,1);
	return printf("%.8lf\n",rs*Pi),0;
}