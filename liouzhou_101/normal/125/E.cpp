#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MaxN=100010;

int n,m,k;
struct node
{
	int x,y,w,p;
	double c;
	bool operator < (const node &A) const
	{
		return c<A.c;
	}
}p[MaxN];

void init()
{
	cin>>n>>m>>k;
	for (int i=1;i<=m;++i)
	{
		scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].w);
		if (p[i].x>p[i].y) swap(p[i].x,p[i].y);
		p[i].p=i;
	}
}

vector<int> v;
int F[MaxN];

int father(int x)
{
	return (F[x]==x)?x:F[x]=father(F[x]);
}

int check(double d)
{
	v.clear();
	random_shuffle(p+1,p+m+1);
	for (int i=1;i<=m;++i)
		p[i].c=(p[i].x==1)?p[i].w+d:p[i].w;
	sort(p+1,p+m+1);
	for (int i=1;i<=n;++i)
		F[i]=i;
	int get=0;
	for (int i=1;i<=m;++i)
	{
		int fx=father(p[i].x),fy=father(p[i].y);
		if (fx==fy) continue;
		v.push_back(p[i].p);
		if (p[i].x==1) ++get;
		F[fx]=fy;
	}
	return get;
}

void work()
{
	double L=-1e5,R=1e5;
	if (!(check(L)>=k&&check(R)<=k))
	{
		puts("-1");
		return;
	}
	while (1)
	{
		double mid=(L+R)/2;
		int get=check(mid);
		if (get==k)
		{
			cout<<n-1<<endl;
			for (int i=0;i<n-1;++i)
				printf("%d ",v[i]);
			return;
		}
		if (get<k)
			R=mid;
		else
			L=mid;
	}
}

int main()
{
	init();
	work();
	return 0;
}