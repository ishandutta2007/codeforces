#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
map<int,map<int,int> > mp;
const int maxn=1e9;
int n,tp,t,x;
void add(int i,int p,int x)
{
	while(p<=maxn)
	{
		mp[i][p]+=x;
		p+=p&(-p);
	}
}
int ans(int i,int p)
{
	int res=0;
	while(p>=1)
	{
		res+=mp[i][p];
		p-=p&(-p);
	}
	return res;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&tp,&t,&x);
		if (tp==1)
		{
			add(x,t,1);
		}
		else if (tp==2)
		{
			add(x,t,-1);
		}
		else
		{
			printf("%d\n",ans(x,t));
		}
	}
	return 0;
}