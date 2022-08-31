#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>

using namespace std;

const int MaxN=100010;

int n,k;
pair<int,int> p[MaxN];
int px,py;

void init()
{
	cin>>n>>k;
	for (int i=1;i<=n;++i)
	{
		scanf("%d",&p[i].first);
		p[i].second=i;
	}
	sort(p+1,p+n+1);
	cin>>px>>py;
}

double getdis(double x1,double y1,double x2,double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

void work()
{
	if (k==n+1)
	{
		printf("%.20lf\n",p[n].first-p[1].first+min(getdis(px,py,p[1].first,0),getdis(px,py,p[n].first,0)));
		return;
	}
	for (int i=1;i<=n;++i)
		if (p[i].second==k)
		{
			k=i;
			break;
		}
	double ans=1e20;
	for (int i=1;i<=k;++i)
	{
		double tmp=p[n].first-p[i].first+min(p[k].first-p[i].first+getdis(px,py,p[n].first,0),p[n].first-p[k].first+getdis(px,py,p[i].first,0));
		if (i>1)
			tmp+=p[i-1].first-p[1].first+min(getdis(px,py,p[1].first,0),getdis(px,py,p[i-1].first,0));
		ans=min(ans,tmp);
	}
	for (int i=k;i<=n;++i)
	{
		double tmp=p[i].first-p[1].first+min(p[k].first-p[1].first+getdis(px,py,p[i].first,0),p[i].first-p[k].first+getdis(px,py,p[1].first,0));
		if (i<n)
			tmp+=p[n].first-p[i+1].first+min(getdis(px,py,p[i+1].first,0),getdis(px,py,p[n].first,0));
		ans=min(ans,tmp);
	}
	printf("%.20lf\n",ans);
}

int main()
{
	init();
	work();
	return 0;
}