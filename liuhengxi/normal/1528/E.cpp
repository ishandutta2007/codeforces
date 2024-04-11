#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e6+5,MOD=998244353,INV3=(MOD+1)/3;
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
void reduce(int &x){(x>=MOD)&&(x-=MOD);}
int n,f[N],g[N],s[N],ans;
int main()
{
	read(n);
	F(i,s[1]=f[0]=1,n+1)
	{
		g[i]=(int)(((long long)f[i-1]*s[i-1]+(f[i-1]*(f[i-1]+1ll)>>1))%MOD);
		reduce(f[i]=f[i-1]+g[i]);
		reduce(s[i+1]=s[i]+f[i]);
	}
	ans=(int)((f[n]+(s[n-1]*(s[n-1]+1ll)>>1)%MOD*f[n-1]+(f[n-1]*(f[n-1]+1ll)>>1)%MOD*s[n-1]+((f[n-1]*(f[n-1]+1ll)>>1)%MOD)*(f[n-1]+2)%MOD*INV3)%MOD);
	reduce(ans<<=1);
	reduce(ans+=MOD-1);
	F(i,0,n-1)ans=(int)((ans+(f[i]+MOD-1ll)*g[n-i-1])%MOD);
	printf("%d\n",ans);
	return 0;
}