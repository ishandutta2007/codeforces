#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<set>
using namespace std;
long long n,m,x,y,v,d,q,x1,yy,x2,y2,pos,ans,anss;
set<long long> s,e;
set<long long>::iterator it;
int main()
{
	scanf("%I64d%I64d%I64d%I64d%I64d",&n,&m,&x,&y,&v);
	for (long long i=1;i<=x;i++)
	{
		scanf("%I64d",&d);
		s.insert(d);
	}
	for (long long i=1;i<=y;i++)
	{
		scanf("%I64d",&d);
		e.insert(d); 
	}
	scanf("%I64d",&q);
	while(q--)
	{
		scanf("%I64d%I64d%I64d%I64d",&x1,&yy,&x2,&y2);
		if (x1==x2)
		{
			printf("%I64d\n",abs(yy-y2));
			continue;
		}
		if (yy>y2) swap(yy,y2);
		if (x1>x2) swap(x1,x2);
		if (!s.empty())
		{
			it=s.lower_bound(yy);
			if (it==s.end())
			{
				it--;
				pos=*it;
			}
			else if (*it>y2)
			{
				if (it==s.begin())
				{
					pos=*it;
				}
				else
				{
					it--;
					pos=*it;
					it=s.lower_bound(y2);
					if (it!=s.end())
					{
						if (abs((*it)-y2)<abs(yy-pos)) pos=*it;
					}
				}
			}
			else pos=yy;
			ans=abs(yy-pos)+abs(y2-pos)+(x2-x1);
		}
		else ans=1e9;
		if (!e.empty())
		{
			it=e.lower_bound(yy);
			if (it==e.end())
			{
				it--;
				pos=*it;
			}
			else if ((*it)>y2)
			{
				if (it==e.begin())
				{
					pos=*it;
				}
				else
				{
					it--;
					pos=*it;
					it=e.lower_bound(y2);
					if (it!=e.end())
					{
						if (abs((*it)-y2)<abs(yy-pos)) pos=*it;
					}
				}
			}
			else pos=yy;
			anss=abs(yy-pos)+abs(y2-pos);
			if ((x2-x1)%v==0) anss+=(x2-x1)/v;
			else anss+=((x2-x1)/v+1);
		}
		else anss=1e9;
		printf("%I64d\n",min(ans,anss));
	}
	return 0;
}