#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=(1<<20)+1;
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
int tt,h,g,a[N],id[N];
bool b[N],d[N];
bool cmp(int u,int v){return a[u]<a[v];}
int main()
{
	read(tt);
	while(tt--)
	{
		long long ans=0;
		read(h,g);
		F(i,1,1<<h)read(a[i]),id[i]=i;
		sort(id+1,id+(1<<h),cmp);
		F(i,0,1<<h)b[i]=true;
		F(i,1,1<<g)b[i]=false;
		F(i,1,1<<h)
		{
			d[id[i]]=false;
			for(int u=id[i];u;u>>=1)if(!b[u]&&b[u<<1]&&b[u<<1|1])
			{
				b[u]=true;
				d[id[i]]=true;
				ans+=a[id[i]];
				break;
			}
		}
		printf("%lld\n",ans);
		for(int i=1<<h;--i;)if(!d[i])printf("%d ",i);
		puts("");
	}
	return 0;
}