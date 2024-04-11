#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5,MOD=1000000007;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int T,n,b[N],f[N],ans,g[N];
long long s[N+1],val[N];
int disc(long long x)
{
	int l=0,r=n+1,mid;
	while(r-l>1)
	{
		mid=(l+r)>>1;
		if(x<val[mid])r=mid;
		else l=mid;
	}
	return l;
}
int main()
{
	read(T);
	while(T--)
	{
		read(n);
		F(i,0,n)read(b[i]);
		s[0]=val[0]=g[n]=0;
		F(i,0,n)val[i+1]=s[i+1]=s[i]+b[i],g[i]=f[i]=0;
		sort(val,val+n+1);
		F(i,0,n)s[i]=disc(s[i]);
		g[s[0]]=f[0]=ans=1;
		F(i,1,n)
		{
			(f[i]=ans+MOD-g[s[i]])%=MOD;
			(ans+=f[i])%=MOD;(g[s[i]]+=f[i])%=MOD;
		}
		printf("%d\n",ans);
	}
	return 0;
}