#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=5e5+5,M=1e7+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,a[N],m,mindiv[M],pri[M],cnt,ans1[N],ans2[N];
bool vis[M];
void init()
{
	F(i,2,m)
	{
		if(!vis[i])pri[cnt++]=mindiv[i]=i;
		F(j,0,cnt)
		{
			int x=i*pri[j];
			if(x>=m)break;
			vis[x]=true;mindiv[x]=pri[j];
			if(i%pri[j]==0)break;
		}
	}
}
int main()
{
	read(n);
	F(i,0,n)read(a[i]),m=a[i]>m?a[i]:m;
	++m;init();
	F(i,0,n)
	{
		ans1[i]=mindiv[a[i]];
		while(a[i]%(ans1[i]*mindiv[a[i]])==0)ans1[i]*=mindiv[a[i]];
		ans2[i]=a[i]/ans1[i];
		if(ans2[i]==1)ans1[i]=ans2[i]=-1;
	}
	F(i,0,n)printf("%d ",ans1[i]);
	puts("");
	F(i,0,n)printf("%d ",ans2[i]);
	puts("");
	return 0;
}