#include <algorithm>
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
struct day
{
	int cost, dissatisfaction;
	int index;
};
int n,m;
day a[200000];
bool p[200000];
bool operator <(day x, day y) //hocu da mi na vrhu bude onaj koji je najmanje povecava nezadovoljstvo kasira
{
	int cx,cy;
	cx=(100-x.cost%100)%100;
	cy=(100-y.cost%100)%100;
	return cx*x.dissatisfaction>cy*y.dissatisfaction;
}
bool operator >(day x, day y) //hocu da mi na vrhu bude onaj koji je navise smanjuje nezadovoljstvo kasira
{
	int cx,cy;
	cx=(100-x.cost%100)%100;
	cy=(100-y.cost%100)%100;
	return cx*x.dissatisfaction<cy*y.dissatisfaction;
}
priority_queue<day> full;
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",&a[i].cost);
	for(int i=0;i<n;i++) scanf("%d",&a[i].dissatisfaction);
	for(int i=0;i<n;i++) a[i].index=i;
	long long int l=0;
	int c,d;
	for(int i=0;i<n;i++)
	{
		p[i]=false;
		if((a[i].cost%100)<=m)
		{
			m-=a[i].cost%100;
			if((a[i].cost%100!=0))full.push(a[i]);
			//cout<<i<<" "<<((100-a[i].cost%100)%100)*a[i].dissatisfaction<<endl;
			p[i]=true;
		}
		else
		{
			if(full.size()>0)
			{
				c=full.top().cost;
				d=full.top().dissatisfaction;
				c=(100-c%100)%100;
				//cout<<full.top().index<<" "<<i<<" "<<c*d<<" "<<((100-a[i].cost%100)%100)*a[i].dissatisfaction<<endl;
				if(c!=0 && c*d<((100-a[i].cost%100)%100)*a[i].dissatisfaction)
				{
					p[full.top().index]=false;
					l=l+c*d;
					m+=100;
					m-=a[i].cost%100;
					p[i]=true;
					full.pop();
					full.push(a[i]);
				}
				else
				{
					c=a[i].cost;
					d=a[i].dissatisfaction;
					c=(100-c%100)%100;
					m+=c;
					l=l+c*d;
				}
			}
			else
			{
				c=a[i].cost;
				d=a[i].dissatisfaction;
				c=(100-c%100)%100;
				m+=c;
				l=l+c*d;
			}
		}
	}
	//cout<<m<<endl;
	printf("%lld\n",l);
	for(int i=0;i<n;i++)
	{
		if(p[i]) printf("%d %d\n",a[i].cost/100,a[i].cost%100);
		else printf("%d %d\n",a[i].cost/100+1,0);
	}
	return 0;
}