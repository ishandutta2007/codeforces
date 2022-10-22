#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5,MOD=998244353;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,x[N],y[N],s[N],f[N],g[N],ans;
int main()
{
	read(n);
	F(i,0,n)read(x[i]),read(y[i]),read(s[i]);
	F(i,0,n)
	{
		int j=lower_bound(x,x+n,y[i])-x;
		f[i]=((long long)MOD+g[i]-g[j]+x[i]-y[i])%MOD;
		g[i+1]=(g[i]+f[i])%MOD;
	}
	ans=x[n-1]+1;
	F(i,0,n)(ans+=f[i]*s[i])%=MOD;
	printf("%d\n",ans);
	return 0;
}