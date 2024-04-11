#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=4e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,a[N],c0[N],c1[N],m0,m1,h[N],l[N],k,ans;
inline int f(int a,int b=k){return a^((a>>b)<<b);}
bool cmp(int u,int v){return f(u,k+1)<f(v,k+1);}
int main()
{
	read(n);
	F(i,0,n)read(a[i]);
	for(k=0;k<25;++k)
	{
		int tot=0;
		sort(a,a+n,cmp);
		m1=m0=0;
		F(i,0,n)if(a[i]&1<<k)c1[m1++]=a[i];else c0[m0++]=a[i];
		for(int i=0,j=m0;i<m0;++i)
		{
			while(j>i+1&&f(c0[i]+c0[j-1])!=f(c0[i])+f(c0[j-1]))--j;
			if(j<i+1)j=i+1;
			tot^=m0-j;
		}
		for(int i=0,j=m1;i<m1;++i)
		{
			while(j>i+1&&f(c1[i]+c1[j-1])!=f(c1[i])+f(c1[j-1]))--j;
			if(j<i+1)j=i+1;
			tot^=m1-j;
		}
		tot^=m0*m1;
		for(int i=0,j=m1;i<m0;++i)
		{
			while(j>0&&f(c0[i]+c1[j-1])!=f(c0[i])+f(c1[j-1]))--j;
			tot^=m1-j;
		}
		ans^=(tot&1)<<k;
	}
	printf("%d\n",ans);
	return 0;
}