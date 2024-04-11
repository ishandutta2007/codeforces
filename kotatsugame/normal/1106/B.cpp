#include<iostream>
#include<queue>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
int a[1<<17], c[1<<17];
main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	priority_queue<pair<int,int> >P;
	for(int i=0;i<n;i++)
	{
		scanf("%d",c+i);
		P.push(make_pair(-c[i],i));
	}
	for(;m--;)
	{
		long long ans=0;
		int t,d;scanf("%d%d",&t,&d);
		t--;
		if(a[t]>=d)
		{
			ans=(long long)c[t]*d;
			a[t]-=d;
			d=0;
		}
		else
		{
			ans=(long long)c[t]*a[t];
			d-=a[t];
			a[t]=0;
		}
		while(d>0)
		{
			while(!P.empty()&&a[P.top().second]==0)P.pop();
			if(!P.empty())
			{
				int id=P.top().second;
				if(a[id]>d)
				{
					ans+=(long long)c[id]*d;
					a[id]-=d;
					d=0;
				}
				else
				{
					ans+=(long long)c[id]*a[id];
					d-=a[id];
					a[id]=0;
					P.pop();
				}
			}
			else break;
		}
		cout<<(d==0?ans:0LL)<<endl;
	}
}