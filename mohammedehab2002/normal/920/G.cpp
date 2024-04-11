#include <iostream>
#include <vector>
using namespace std;
int p,lp[10000005];
vector<int> v;
void con(int x)
{
	if (x==1)
	return;
	if (lp[x]!=lp[x/lp[x]])
	v.push_back(lp[x]);
	con(x/lp[x]);
}
int go(int m)
{
	int res=0;
	for (int i=0;i<(1<<v.size());i++)
	{
		int ans=1,cnt=0;
		for (int x=0;x<v.size();x++)
		{
			if (i&(1<<x))
			ans*=v[x],cnt++;
		}
		if (cnt%2)
		res-=m/ans;
		else
		res+=m/ans;
	}
	return res;
}
int main()
{
	lp[1]=1;
	for (int i=2;i<=10000000;i++)
	{
		if (!lp[i])
		{
			for (int x=i;x<=10000000;x+=i)
			{
				if (!lp[x])
				lp[x]=i;
			}
		}
	}
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int x,k;
		scanf("%d%d%d",&x,&p,&k);
		v.clear();
		con(p);
		int st=1,en=10000000;
		while (st!=en)
		{
			int mid=(st+en)/2;
			if (go(mid)-go(x)<k)
			st=mid+1;
			else
			en=mid;
		}
		printf("%d\n",st);
	}
}