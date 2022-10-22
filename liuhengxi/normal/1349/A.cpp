#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,a[N],m,pri[N],ind[2*N],cnt,c[N],b[N];
long long ans=1;
bool vis[2*N];
int main()
{
	read(n);
	F(i,0,n)read(a[i]),m=a[i]>m?a[i]:m;
	F(i,2,m+1)
	{
		if(!vis[i])pri[ind[i]=cnt++]=i;
		F(j,0,cnt)
		{
			if(i*pri[j]>m)break;
			vis[i*pri[j]]=true;
			if(i%pri[j]==0)break;
		}
	}
	F(i,0,n)
	{
		int t=a[i];
		for(int j=0;t!=1&&vis[t];++j)if(t%pri[j]==0)
		{
			++c[j];
			while(t%pri[j]==0)t/=pri[j];
		}
		if(t!=1)++c[ind[t]];
	}
	F(j,0,cnt)if(c[j]>n-2)
	{
		F(i,0,n)
		{
			b[i]=0;
			for(int t=a[i];t%pri[j]==0;t/=pri[j])++b[i];
		}
		F(i,0,n-1)if(b[i]<b[i+1])b[i]^=b[i+1]^=b[i]^=b[i+1];
		F(i,0,n-1)if(b[i]<b[i+1])b[i]^=b[i+1]^=b[i]^=b[i+1];
		F(i,0,b[n-2])ans*=pri[j];
	}
	printf("%lld\n",ans);
	return 0;
}