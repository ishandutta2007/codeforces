#include<cstdio>
#include<cstring>
#include<algorithm>
#define int long long
using std::sort;
inline double abs(double x)
{
	return x<0?-x:x;
}
const int N=1e5+5;
const double eps=1e-12;
int n,w;
int ans;
int x[N],v[N];
double b[N];
struct cell
{
	double a,b;
}e[N],f[N];
inline bool cmpa(cell x,cell y)
{
	if(abs(x.a-y.a)>eps)
		return x.a<y.a;
	return x.b>y.b;
}
void solve(int l,int r)
{
	if(l==r)
		return;
	int mid=(l+r)>>1;
	solve(l,mid);solve(mid+1,r);
	register int i=l,j=mid+1,k=l;
	while(i<=mid&&j<=r)
		if(e[i].b<e[j].b-eps)
			f[k++]=e[i++];
		else
			ans+=mid-i+1,f[k++]=e[j++];
	while(i<=mid)
		f[k++]=e[i++];
	while(j<=r)
		f[k++]=e[j++];
	memmove(e+l,f+l,sizeof(cell)*(r-l+1));
	return;
}
signed main()
{
	register int i;
	scanf("%lld%lld",&n,&w);
	for(i=1;i<=n;i++)
		scanf("%lld%lld",&x[i],&v[i]),v[i]*=-1;
	for(i=1;i<=n;i++)
	{
		b[i]=(double)v[i]/x[i];
		e[i].a=(double)(-w)/x[i]+b[i];
		e[i].b=(double)w/x[i]+b[i];
	}
	sort(e+1,e+n+1,cmpa);
	solve(1,n);
	printf("%lld\n",ans);
	return 0;
}