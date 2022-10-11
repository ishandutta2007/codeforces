#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector<int> d[500005];
int arr[200005],cnt[500005];
long long ans;
set<int> s;
int sign(int x)
{
	return (x%2? -1:1);
}
void add(int v,int m)
{
	for (int i=0;i<(1<<d[v].size());i++)
	{
		int p=1,c=0;
		for (int x=0;x<d[v].size();x++)
		{
			if (i&(1<<x))
			p*=d[v][x],c++;
		}
		if (m==1)
		ans+=cnt[p]*sign(c);
		cnt[p]+=m;
		if (m==-1)
		ans-=cnt[p]*sign(c);
	}
}
int main()
{
	for (int i=2;i<500005;i++)
	{
		if (d[i].empty())
		{
			for (int x=i;x<500005;x+=i)
			d[x].push_back(i);
		}
	}
	int n,q;
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++)
	scanf("%d",&arr[i]);
	while (q--)
	{
		int x;
		scanf("%d",&x);
		if (s.find(x)==s.end())
		{
			add(arr[x],1);
			s.insert(x);
		}
		else
		{
			add(arr[x],-1);
			s.erase(x);
		}
		printf("%I64d\n",ans);
	}
}