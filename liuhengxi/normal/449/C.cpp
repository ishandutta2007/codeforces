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
int n,m,a[N];
bool pri[N],mat[N];
int main()
{
	read(n);
	F(i,2,n+1)pri[i]=true;
	F(i,2,n/2+1)for(int j=i<<1;j<=n;j+=i)pri[j]=false;
	F(i,3,n/2+1)if(pri[i])
	{
		int tot=0;
		for(int j=i;j<=n;j+=i)if(!mat[j])++tot;
		for(int j=i;j<=n;j+=i)if(!mat[j])
		{
			if((tot&1)&&j==(i<<1))continue;
			mat[a[m++]=j]=true;
		}
	}
	for(int i=2;i<n;i+=2)if(!mat[i])a[m++]=i;
	printf("%d\n",m>>=1);
	F(i,0,m)printf("%d %d\n",a[i<<1],a[i<<1|1]);
	return 0;
}