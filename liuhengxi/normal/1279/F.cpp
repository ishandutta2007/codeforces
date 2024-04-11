// LUOGU_RID: 90585440
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
constexpr int N=1e6+5;
int n,k,t,s[N],q[N],qf,qr,g[N];
long long f[N];
bool dp(int p)
{
	f[0]=0;
	qf=qr=0;
	q[qr++]=0;
	F(i,1,n+1)
	{
		while(q[qf]<i-t)++qf;
		if(f[i-1]+s[i]-s[i-1]<f[q[qf]]+p)f[i]=f[i-1]+s[i]-s[i-1],g[i]=g[i-1];
		else f[i]=f[q[qf]]+p,g[i]=g[q[qf]]+1;
		while(qf<qr&&f[q[qr-1]]>=f[i])--qr;
		q[qr++]=i;
	}
	return g[n]>=k;
}
int solve()
{
	int l=-1,r=1e6+1,mid;
	while(r-l>1)
	{
		mid=(l+r)>>1;
		if(dp(mid))l=mid;
		else r=mid;
	}
	dp(l);
	return (int)(f[n]-(long long)l*k);
}
char str[N];
int main()
{
	read(n,k,t);
	scanf("%s",str);
	F(i,0,n)s[i+1]=s[i]+(str[i]>>5&1);
	int ans1=solve();
	F(i,0,n)s[i+1]=s[i]+(~str[i]>>5&1);
	int ans2=solve();
	printf("%d\n",min(ans1,ans2));
	return 0;
}