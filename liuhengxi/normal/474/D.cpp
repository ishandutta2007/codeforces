#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,MOD=1000000007;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int t,k,f[N]={1};
int main()
{
	read(t);read(k);
	F(i,1,N)
	{
		f[i]=f[i-1];
		if(i>=k)(f[i]+=f[i-k])%=MOD;
	}
	F(i,0,N-1)(f[i+1]+=f[i])%=MOD;
	while(t--)
	{
		int a,b,ans;read(a);read(b);--a;
		ans=f[b]-f[a];
		ans+=MOD;ans%=MOD;
		printf("%d\n",ans);
	}
	return 0;
}