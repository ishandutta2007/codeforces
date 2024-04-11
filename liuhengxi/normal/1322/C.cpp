#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=5e5+5,MOD=928551199,P=953;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int t,n,m,a[N],b[N],id[N];
long long c[N];
bool cmp(int u,int v){return a[u]<a[v];}
long long gcd(long long a,long long b){return !b?a:gcd(b,a%b);}
int main()
{
	read(t);
	b[0]=1;
	F(i,1,N)b[i]=b[i-1]*(long long)P%MOD;
	while(t--)
	{
		long long ans=0,sum=0;
		read(n);read(m);
		F(i,0,n)read(c[i]),a[id[i]=i]=0;
		F(i,0,m)
		{
			int u,v;read(u);read(v);--u,--v;
			(a[v]+=b[u])%=MOD;
		}
		sort(id,id+n,cmp);
		F(i,0,n)
		{
			if(!a[id[i]])continue;
			if(i&&a[id[i]]!=a[id[i-1]])ans=gcd(ans,sum),sum=0;
			sum+=c[id[i]];
		}
		ans=gcd(ans,sum);
		printf("%lld\n",ans);
	}
	return 0;
}