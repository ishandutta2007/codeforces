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
constexpr int N=105;
int tt,n,c,a[N],d[N];
int main()
{
	read(tt);
	while(tt--)
	{
		read(n,c);
		F(i,0,n)++d[--read(a[i])];
		int ans=0;
		F(i,0,n)if(d[a[i]])
		{
			ans+=min(c,d[a[i]]);
			d[a[i]]=0;
		}
		printf("%d\n",ans);
	}
	return 0;
}