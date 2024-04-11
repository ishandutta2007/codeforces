#include<cstdio>
#include<algorithm>
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
int n,m,a[25][N],ans=100,b[25],d[25];
bool rec;
void dfs(int n,int dep,int now)
{
	int m=0,c0=0,c1=0,last=0;
	if(n==1&&(a[dep][0]==now||a[dep][0]==-now))
	{
		b[dep]=a[dep][0];
		++dep;
		if(rec)
		{
			if(dep<ans)
			{
				ans=dep;
				F(i,0,dep)d[i]=b[i];
			}
		}
		else if(dep<ans)ans=dep;
		return;
	}
	if(n==0)
	{
		if(rec)
		{
			if(dep<ans)
			{
				ans=dep;
				F(i,0,dep)d[i]=b[i];
			}
		}
		else if(dep<ans)ans=dep;
		return;
	}
	F(i,0,n)
	{
		int c=a[dep][i];
		if(c&now)c-=now,c0=1;
		if(c)if(i==0||c!=last)a[dep+1][m++]=c;
		last=c;
	}
	b[dep]=now;
	dfs(m,dep+c0,now<<1);
	m=0;
	F(i,0,n)
	{
		int c=a[dep][i];
		if(c&now)c+=now,c1=1;
		if(c)if(i==0||c!=last)a[dep+1][m++]=c;
		last=c;
	}
	b[dep]=-now;
	dfs(m,dep+c1,now<<1);
}
int main()
{
	int m=0;
	read(n);
	F(i,0,n)read(a[0][i]);
	sort(a[0],a[0]+n);
	F(i,0,n)if(a[0][i])if(i==0||a[0][i]!=a[0][i-1])a[1][m++]=a[0][i];
	n=m;
	F(i,0,n)a[0][i]=a[1][i];
	dfs(n,0,1);
	rec=true;
	++ans;
	dfs(n,0,1);
	printf("%d\n",ans);
	F(i,0,ans)printf("%d ",d[i]);
	printf("\n");
	return 0;
}