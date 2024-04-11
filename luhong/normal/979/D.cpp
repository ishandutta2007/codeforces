#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
set<int> st[100001];
int main()
{
	int q;scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int t,u,x,k,s;scanf("%d",&t);
		if(t==1)
		{
			scanf("%d",&u);
			for(int j=1;j*j<=u;j++)
			{
				if(j*j==u)st[j].insert(u);
				else if(u%j==0)st[j].insert(u),st[u/j].insert(u);
			}
		}
		else
		{
			scanf("%d%d%d",&x,&k,&s);
			if(x%k!=0){puts("-1");continue;}
			set<int>::iterator it;it=st[k].lower_bound(0);
			if(it==st[k].end()||(*it)>s-x){puts("-1");continue;}
			int now=0;
			for(int j=17;j>=0;j--)
			{
				if((x>>j)&1)
				{
					it=st[k].lower_bound(now);
					if(((*it)>>j)&1)now+=(1<<j); 
				}
				else
				{
					int o=1<<j;
					it=st[k].lower_bound(o+now);
					if(it!=st[k].end()&&(*it)<=s-x&&(*it)<=now+o+o-1)now+=o;
				}
			}
			printf("%d\n",now);
		}
	}
	return 0;
}