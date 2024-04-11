#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=105;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int t,a[N][2],c[2*N];
bool b[2*N];
int main()
{
	read(t);
	while(t--)
	{
		int n,k,ans=0,m=0;
		read(n);read(k);
		F(i,0,2*n)b[i]=false;
		F(i,0,k)
		{
			read(a[i][0]);read(a[i][1]);
			if(a[i][0]>a[i][1])swap(a[i][0],a[i][1]);
			b[--a[i][0]]=true;
			b[--a[i][1]]=true;
		}
		F(i,0,2*n)if(!b[i])c[m++]=i;
		F(i,k,n)a[i][0]=c[i-k],a[i][1]=c[i-k+n-k];
		F(i,0,n)F(j,0,i)
		{
			int r=0;
			if(a[i][0]>=a[j][0]&&a[i][0]<=a[j][1])++r;
			if(a[i][1]>=a[j][0]&&a[i][1]<=a[j][1])++r;
			if(r&1)++ans;
		}
		printf("%d\n",ans);
	}
	return 0;
}