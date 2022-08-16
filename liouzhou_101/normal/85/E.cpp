#include<cstdio>
#include<cstdlib>
#include<iostream>

using namespace std;

const int MaxN=10010;
const int MaxM=13000010;
const int MOD=1000000007;

int n;
int x[MaxN],y[MaxN];

int m;
struct node
{
	int x,y;
	node *p;
}p[MaxM],*v[MaxN];

void init()
{
	cin>>n;
	for (int i=1;i<=n;++i)
		scanf("%d%d",&x[i],&y[i]);
	for (int i=1;i<=n;++i)
		for (int j=i+1;j<=n;++j)
		{
			int d=abs(x[i]-x[j])+abs(y[i]-y[j]);
			++m;
			p[m].x=i;
			p[m].y=j;
			p[m].p=v[d];
			v[d]=&p[m];
		}
}

int F[MaxN],G[MaxN];

inline int father(const int &x)
{
	if (F[x]==x) return x;
	int p=F[x];
	F[x]=father(p);
	G[x]^=G[p];
	return F[x];
}

void work()
{
	int ans=0;
	for (int i=1;i<=n;++i)
		F[i]=i;
	int pre=n;
	for (int d=10000;d>=0;--d)
	{
		int flag=0;
		int now=pre;
		for (node *it=v[d];it;it=it->p)
		{
			int fx=father(it->x),fy=father(it->y);
			if (fx==fy&&G[it->x]==G[it->y])
			{
				flag=1;
				break;
			}
			if (fx==fy) continue;
			F[fy]=fx;
			G[fy]=G[it->x]^G[it->y]^1;
			--now;
		}
		if (flag)
		{
			ans=d;
			break;
		}
		pre=now;
	}
	cout<<ans<<endl;
	int cnt=1;
	for (int i=1;i<=pre;++i)
		if ((cnt<<=1)>=MOD) cnt-=MOD;
	cout<<cnt<<endl;
}

int main()
{
	init();
	work();
	return 0;
}