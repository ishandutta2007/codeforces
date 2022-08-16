#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

const int MaxN=1<<17;

int n;
long long a,b,c,d;

struct node
{
	int tx,ty;
	long long x,y;
}p[MaxN];

inline bool cmp(const node &A,const node &B)
{
	return A.x<B.x||A.x==B.x&&A.y>B.y;
}

void init()
{
	cin>>n;
	scanf("%I64d/%I64d %I64d/%I64d",&a,&b,&c,&d);
	for (int i=1;i<=n;++i)
	{
		int tx,ty;
		scanf("%d%d",&tx,&ty);
		p[i].tx=tx;
		p[i].ty=ty;
		p[i].x=c*tx-d*ty;
		p[i].y=b*ty-a*tx;
	}
}

long long F[MaxN];
//int G[MaxN];
int ans;

void work()
{
	sort(p+1,p+n+1,cmp);
	F[ans=1]=0;
	for (int i=1;i<=n;++i)
	{
		if (p[i].x<=0) continue;
		if (F[1]>=p[i].y) continue;
		if (F[ans]<p[i].y)
		{
			F[++ans]=p[i].y;
		//	G[ans]=i;
			continue;
		}
		int L=1,R=ans-1;
		while (L<=R)
		{
			int m=(L+R)>>1;
			if (F[m]<p[i].y&&F[m+1]>=p[i].y)
			{
				F[m+1]=p[i].y;
			//	G[m+1]=i;
				break;
			}
			if (F[m]<p[i].y)
				L=m+1;
			else
				R=m-1;
		}
	}
	cout<<ans-1<<endl;
	//for (int i=2;i<=ans;++i)
	//	cout<<p[G[i]].tx<<" "<<p[G[i]].ty<<endl;
}

int main()
{
	init();
	work();
	return 0;
}