#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=50,INF=0x3fffffff;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int T,n,a[N],b[N];
long long ans;
int main()
{
	read(T);
	while(T--)
	{
		int mina=INF,minb=INF;
		ans=0;
		read(n);
		F(i,0,n)read(a[i]);
		F(i,0,n)read(b[i]);
		F(i,0,n)if(a[i]<mina)mina=a[i];
		F(i,0,n)if(b[i]<minb)minb=b[i];
		F(i,0,n)
		{
			int tmpa,tmpb;
			tmpa=a[i]-mina;
			tmpb=b[i]-minb;
			ans+=tmpa>tmpb?tmpa:tmpb;
		}
		printf("%lld\n",ans);
	}
	return 0;
}