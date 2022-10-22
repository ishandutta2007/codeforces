#include<cstdio>
#include<algorithm>
#include<functional>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=3e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,m,val[4][N],cnt[4];
long long f[N],g[N],sum,ans;
int main()
{
	read(n);read(m);
	F(i,0,n)
	{
		int w,c;read(w);read(c);
		val[w][cnt[w]++]=c;
	}
	sort(val[1],val[1]+cnt[1],greater<int>());
	sort(val[2],val[2]+cnt[2],greater<int>());
	sort(val[3],val[3]+cnt[3],greater<int>());
	for(int i=0,j=0,k=0;i<=m;i+=2)
	{
		f[i]=sum;
		if(val[1][j]+val[1][j+1]>val[2][k])sum+=val[1][j++],sum+=val[1][j++];
		else sum+=val[2][k++];
	}
	sum=val[1][0];
	for(int i=1,j=1,k=0;i<=m;i+=2)
	{
		f[i]=sum;
		if(val[1][j]+val[1][j+1]>val[2][k])sum+=val[1][j++],sum+=val[1][j++];
		else sum+=val[2][k++];
	}
	F(i,1,m+1)f[i]=max(f[i],f[i-1]);
	F(i,3,m+1)g[i]=g[i-3]+val[3][(i-3)/3];
	F(i,0,m+1)ans=max(ans,f[i]+g[m-i]);
	printf("%lld\n",ans);
	return 0;
}