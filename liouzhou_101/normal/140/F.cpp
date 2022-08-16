#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MaxN=200010;

int n,k;
pair<int,int> a[MaxN];
vector<pair<int,int> > v;

void init()
{
	cin>>n>>k;
	for (int i=1;i<=n;++i)
		scanf("%d%d",&a[i].first,&a[i].second);
	sort(a+1,a+n+1);
}

void check(int px,int py)
{
	int p=0;
	for (int i=1,j=n;i<=n;++i)
	{
		pair<int,int> c=make_pair(px-a[i].first,py-a[i].second);
		while (j>1&&a[j]>c) --j;
		if (j&&a[j]==make_pair(px-a[i].first,py-a[i].second))
			--j;
		else
			if (++p>k) return;
	}
	v.push_back(make_pair(px,py));
}

void work()
{
	if (n<=k)
	{
		puts("-1");
		return;
	}
	for (int i=1;i<=k+1;++i)
		for (int j=n-k;j<=n;++j)
			check(a[i].first+a[j].first,a[i].second+a[j].second);
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	cout<<v.size()<<endl;
	for (int i=0;i<v.size();++i)
		printf("%lf %lf\n",v[i].first*0.5,v[i].second*0.5);
}

int main()
{
	init();
	work();
	return 0;
}