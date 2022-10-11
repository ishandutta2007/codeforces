#include <bits/stdc++.h>
using namespace std;
int a[10005];
vector<pair<pair<int,int>,int> > ans;
int go(int i,int j,int x)
{
	ans.push_back({{i,j},x});
	a[i]-=i*x;
	a[j]+=i*x;
}
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		ans.clear();
		int n;
		scanf("%d",&n);
		int avg=0;
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			avg+=a[i];
		}
		if (avg%n)
		{
			puts("-1");
			continue;
		}
		avg/=n;
		for (int i=2;i<=n;i++)
		{
			go(1,i,(i-a[i]%i)%i);
			go(i,1,a[i]/i);
		}
		for (int i=2;i<=n;i++)
		go(1,i,avg);
		printf("%d\n",ans.size());
		for (auto p:ans)
		printf("%d %d %d\n",p.first.first,p.first.second,p.second);
	}
}