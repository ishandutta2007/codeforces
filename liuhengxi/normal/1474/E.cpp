#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
int tt,n,p[N],x[N],y[N];
int main()
{
	for(read(tt);tt--;)
	{
		int l,r;long long ans=0;
		read(n);
		l=((n+1)>>1)-1;r=(n+1)>>1;
		F(i,0,n)p[i]=i;
		F(i,0,n-2)
		{
			if(i&1)x[i]=r++,y[i]=0;
			else x[i]=l--,y[i]=n-1;
		}
		if(n&1)x[n-2]=0,y[n-2]=n-1;
		else x[n-2]=n-1,y[n-2]=0;
		for(int i=n-1;~--i;)
		{
			ans+=(y[i]-x[i])*(long long)(y[i]-x[i]);
			swap(p[x[i]],p[y[i]]);
		}
		printf("%lld\n",ans);
		F(i,0,n)printf("%d ",p[i]+1);
		puts("");
		printf("%d\n",n-1);
		F(i,0,n-1)printf("%d %d\n",x[i]+1,y[i]+1);
		#ifdef LOCAL
		F(i,0,n-1)
		{
			if(p[y[i]]!=x[i])return puts("wrong");
			swap(p[x[i]],p[y[i]]);
		}
		#endif
	}
	return 0;
}