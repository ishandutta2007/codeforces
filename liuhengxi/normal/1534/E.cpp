#include<cstdio>
#include<stack>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=505,INF=0x3fffffff;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,k,ans,dis[N],pre[N],q[N],qf,qr,c[N];
stack<int> s[3];
int main()
{
	read(n);read(k);
	if((k&1)<(n&1))return puts("-1"),0;
	q[qr++]=0;
	F(i,1,n+1)dis[i]=INF;
	while(qf<qr)
	{
		int u=q[qf++];
		F(i,max(0,k-u),min(k,n-u)+1)
		{
			int v=u+i-(k-i);
			if(dis[v]>dis[u]+1)
			{
				dis[v]=dis[u]+1;pre[v]=i;
				q[qr++]=v;
			}
		}
	}
	for(int i=n,j=dis[n]-1;i;i-=pre[i]-(k-pre[i]),--j)c[j]=pre[i];
	F(i,0,n)s[0].push(i+1);
	F(i,0,dis[n])
	{
		printf("? ");
		F(j,0,c[i])
		{
			printf("%d ",s[0].top());
			s[2].push(s[0].top());s[0].pop();
		}
		F(j,0,k-c[i])
		{
			printf("%d ",s[1].top());
			s[0].push(s[1].top());s[1].pop();
		}
		while(!s[2].empty())s[1].push(s[2].top()),s[2].pop();
		puts("");
	}
	fflush(stdout);
	F(i,0,dis[n])
	{
		int a;read(a);ans^=a;
	}
	printf("! %d\n",ans);
	return 0;
}