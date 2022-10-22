// LUOGU_RID: 90275057
// LUOGU_RID: 90224721
#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
constexpr int N=1.5e5+5;
constexpr double eps=1e-14;
struct problem
{
	int p,t,rp;
	friend bool operator<(problem u,problem v){return (long long)u.p*v.t>(long long)v.p*u.t;}
	friend bool operator==(problem u,problem v){return (long long)u.p*v.t==(long long)v.p*u.t;}
}a[N];
int n,v[N];
long long st;
double b[N];
void add(int x,double y){for(++x;x<=n;x+=x&-x)b[x]=max(b[x],y);}
double sum(int x)
{
	double ans=0.0;
	for(;x;x-=x&-x)ans=max(ans,b[x]);
	return ans;
}
bool check(double c)
{
	F(i,0,n+1)b[i]=0.0;
	long long cur=0;
	for(int l=0,r=0;l<n;l=r)
	{
		while(r<n&&a[l]==a[r])++r;
		F(i,l,r)add(a[i].rp,a[i].p*(1.0-c*(double)(cur+a[i].t)/(double)st));
		F(i,l,r)cur+=a[i].t;
		F(i,l,r)if(sum(a[i].rp)>a[i].p*(1.0-c*(double)cur/(double)st))return false;
	}
	return true;
}
double solve()
{
	double l=0.0,r=1.0,mid;
	while(r-l>eps)
	{
		mid=l+(r-l)/2.0;
		if(check(mid))l=mid;
		else r=mid;
	}
	return l;
}
int main()
{
	read(n);
	F(i,0,n)v[i]=read(a[i].p);
	F(i,0,n)st+=read(a[i].t);
	sort(a,a+n);
	sort(v,v+n);
	F(i,0,n)a[i].rp=(int)(lower_bound(v,v+n,a[i].p)-v);
	printf("%.12lf\n",solve());
	return 0;
}