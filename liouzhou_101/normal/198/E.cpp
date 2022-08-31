#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

const int MaxN=250010;
const int LIMIT=500;

int n;
long long x0,y0;
struct node
{
	long long d,r;
	int m,p;
}p[MaxN];

bool cmp_d(node A,node B)
{
	return A.d<B.d;
}

bool cmp_m(node A,node B)
{
	return A.m<B.m;
}

int tot;
int L[MaxN],R[MaxN];
long long maxd[MaxN];

void init()
{
	cin>>x0>>y0>>p[0].p>>p[0].r>>n;
	p[0].r*=p[0].r;
	for (int i=1;i<=n;++i)
	{
		int px,py;
		scanf("%d%d%d%d%I64d",&px,&py,&p[i].m,&p[i].p,&p[i].r);
		p[i].r*=p[i].r;
		p[i].d=(x0-px)*(x0-px)+(y0-py)*(y0-py);
	}
	sort(p+1,p+n+1,cmp_d);
	for (int i=1;i<=n;i+=LIMIT)
	{
		++tot;
		L[tot]=i;
		R[tot]=min(n,i+LIMIT-1);
		maxd[tot]=p[R[tot]].d;
		sort(p+L[tot],p+R[tot]+1,cmp_m);
	}
}

int head,tail,Q[MaxN];
int used[MaxN];

void work()
{
	Q[head=tail=0]=0;
	while (head<=tail)
	{
		long long nowr=p[Q[head]].r;
		int nowp=p[Q[head]].p;
		++head;
		for (int i=1;i<=tot;++i)
		{
			if (L[i]>R[i]) continue;
			if (maxd[i]>nowr)
			{
				for (int j=L[i];j<=R[i];++j)
					if (!used[j]&&p[j].d<=nowr&&p[j].m<=nowp)
					{
						used[j]=1;
						Q[++tail]=j;
					}
				break;
			}
			while (L[i]<=R[i]&&p[L[i]].m<=nowp)
			{
				if (!used[L[i]]) Q[++tail]=L[i];
				++L[i];
			}
		}
	}
	cout<<tail<<endl;
}

int main()
{
	init();
	work();
	return 0;
}