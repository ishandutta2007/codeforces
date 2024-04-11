#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5;
const long long LLINF=0x3fffffffffffffffll;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,aa[N],id[N],a[N],p[N],pp,k,ans[N];
long long f[N],ff,res;
bool cmp(int u,int v){return aa[u]<aa[v];}
int main()
{
	read(n);
	F(i,0,n)read(aa[i]);
	F(i,0,n)id[i]=i;
	sort(id,id+n,cmp);
	F(i,0,n)a[i]=aa[id[i]];
	f[0]=-a[0];
	f[1]=LLINF;
	f[2]=LLINF;
	ff=f[0];pp=0;
	F(i,2,n)
	{
		f[i+1]=ff+a[i]-a[i+1];
		p[i+1]=pp;
		if(f[i-1]<ff)
		{
			ff=f[i-1];
			pp=i-1;
		}
	}
	res=f[n];
	for(int i=n;i;i=p[i],++k)F(j,p[i],i)ans[id[j]]=k;
	printf("%lld %d\n",res,k);
	F(i,0,n)printf("%d ",ans[i]+1);
	printf("\n");
	return 0;
}