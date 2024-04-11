#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=5e5+5,MOD=998244353;
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
int n,k,m,l[N],r[N],x[N],b[N],c[N],f[N],s[N],ans=1;
int main()
{
	read(n,k,m);++n;
	F(i,0,m)read(l[i],r[i],x[i]),--l[i];
	for(int bit=1<<k;bit>>=1;)
	{
		F(i,0,n)b[i]=f[i]=s[i]=0,c[i]=-1;
		F(i,0,m)if(x[i]&bit)++b[l[i]],--b[r[i]];else c[r[i]]=max(c[r[i]],l[i]);
		F(i,0,n-1)b[i+1]+=b[i],c[i+1]=max(c[i+1],c[i]);
		s[0]=1;
		F(i,0,n)
		{
			if(!b[i])f[i]=(s[i]-(~c[i]?s[c[i]]:0)+MOD)%MOD;
			s[i+1]=(s[i]+f[i])%MOD;
		}
		ans=ans*(long long)f[n-1]%MOD;
	}
	printf("%d\n",ans);
	return 0;
}