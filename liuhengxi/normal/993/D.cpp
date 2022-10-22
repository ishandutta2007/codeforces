#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=55;
const long long LLINF=0x3fffffffffffffffll;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
struct task
{
	int a,b;
	bool operator<(task v)const{return a!=v.a?a>v.a:b<v.b;}
}a[N];
int n;
long long c[N],f[N][2*N];
bool check(long long v)
{
	F(i,0,n)c[i]=a[i].b*v-a[i].a*1000ll;
	F(i,0,n+1)F(j,0,n+1)f[i][j]=-LLINF;
	f[0][0]=0;
	for(int l=0,r=0;l<n;l=r)
	{
		while(a[r].a==a[l].a)++r;
		F(dp/*depend*/,0,r-l+1)
		{
			int delta=r-l-dp-dp;
			long long idsum=0/*independent sum*/;
			F(i,l+dp,r)idsum+=c[i];
			F(i,dp,l+1)f[r][i+delta]=max(f[r][i+delta],f[l][i]+idsum);
		}
		for(int i=n;~--i;)f[r][i]=max(f[r][i],f[r][i+1]);
	}
	return f[n][0]>=0;
}
long long solve()
{
	long long l=0,r=1e11+3,mid;
	while(r-l>1)
	{
		mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid;
	}
	return r;
}
int main()
{
	F(i,0,read(n))read(a[i].a);
	F(i,0,n)read(a[i].b);
	sort(a,a+n);
	printf("%lld\n",solve());
	return 0;
}