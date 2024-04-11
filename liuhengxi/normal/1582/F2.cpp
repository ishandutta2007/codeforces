#include<cstdio>
#include<stack>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e6+5,M=(1<<13)+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
stack<int> sta[M];
int n,m,a[N],f[M],ans;
int main()
{
	read(n);
	F(i,0,n)read(a[i]),m|=a[i];
	m|=m>>1;m|=m>>2;m|=m>>4;m|=m>>8;++m;
	f[0]=0;
	F(i,0,m)sta[i].push(0);
	F(i,1,m)f[i]=m;
	F(i,0,n)
	{
		int u=a[i];
		while(!sta[u].empty())
		{
			int v=sta[u].top()^u;sta[u].pop();
			while(f[v]>u)sta[--f[v]].push(v);
		}
	}
	F(i,0,m)if(f[i]<m)++ans;
	printf("%d\n",ans);
	F(i,0,m)if(f[i]<m)printf("%d ",i);
	puts("");
	return 0;
}