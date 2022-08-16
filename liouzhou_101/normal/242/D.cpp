#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

const int MaxN=100010;

int n,m;
vector<int> v[MaxN];
int a[MaxN],b[MaxN],u[MaxN];
set<int> H;

int main()
{
	cin>>n>>m;
	for (int i=1;i<=m;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;++i)
		if (a[i]==b[i]) H.insert(i);
	while (!H.empty())
	{
		int x=*H.begin();
		int d=(u[x])?-1:1;
		for (vector<int>::iterator it=v[x].begin();it!=v[x].end();++it)
		{
			int s=b[*it]+d;
			if (b[*it]==a[*it])
				H.erase(*it);
			if (s==a[*it])
				H.insert(*it);
			b[*it]=s;
		}
		u[x]^=1;b[x]+=d;
		H.erase(x);
	}
	int p=0;
	for (int i=1;i<=n;++i)
		p+=u[i];
	cout<<p<<endl;
	for (int i=1;i<=n;++i)
		if (u[i]) printf("%d ",i);
	return 0;
}