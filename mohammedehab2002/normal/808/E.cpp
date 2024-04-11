#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<long long> v[3];
int m;
long long go(int x)
{
	return (x? v[1][x-1]:0)+(min(m-2*x,(int)v[0].size())>0? v[0][min(m-2*x,(int)v[0].size())-1]:0);
}
int main()
{
	int n;
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		v[a-1].push_back(b);
	}
	for (int i=0;i<3;i++)
	{
		sort(v[i].rbegin(),v[i].rend());
		for (int x=1;x<v[i].size();x++)
		v[i][x]+=v[i][x-1];
	}
	long long ans=0;
	for (int i=0;i<=v[2].size();i++)
	{
		if (i)
		m-=3;
		if (m<0)
		break;
		int st=0,en=min((int)v[1].size(),m/2);
		while (st!=en)
		{
			int x=(en-st)/3;
			if (go(st+x)>=go(en-x))
			en=en-x-1;
			else
			st=st+x+1;
		}
		ans=max(ans,(i? v[2][i-1]:0)+go(st));
	}
	printf("%I64d",ans);
}