#include<cstdio>
#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

int n,m;
int a[110][110];
int sx[110],sy[110];
int fx[110],fy[110];

set<pair<int,pair<int,int> > > H;

int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
			scanf("%d",&a[i][j]);
	for (int i=1;i<=n;++i)
	{
		int get=0;
		for (int j=1;j<=m;++j)
			get+=a[i][j];
		sx[i]=get;
		H.insert(make_pair(sx[i],make_pair(i,0)));
	}
	for (int i=1;i<=m;++i)
	{
		int get=0;
		for (int j=1;j<=n;++j)
			get+=a[j][i];
		sy[i]=get;
		H.insert(make_pair(sy[i],make_pair(i,1)));
	}
	while (1)
	{
		set<pair<int,pair<int,int> > >::iterator it=H.begin();
		int sum=it->first;
		int way=it->second.first;
		int pos=it->second.second;
		H.erase(it);
		if (sum>=0) break;
		if (pos)
		{
			fy[way]^=1;
			for (int i=1;i<=n;++i)
			{
				a[i][way]=-a[i][way];
				H.erase(make_pair(sx[i],make_pair(i,0)));
				sx[i]+=a[i][way]*2;
				H.insert(make_pair(sx[i],make_pair(i,0)));
			}
			sy[way]=-sy[way];
			H.insert(make_pair(sy[way],make_pair(way,1)));
		}
		else
		{
			fx[way]^=1;
			for (int i=1;i<=m;++i)
			{
				a[way][i]=-a[way][i];
				H.erase(make_pair(sy[i],make_pair(i,1)));
				sy[i]+=a[way][i]*2;
				H.insert(make_pair(sy[i],make_pair(i,1)));
			}
			sx[way]=-sx[way];
			H.insert(make_pair(sx[way],make_pair(way,0)));
		}
	}
	int get=0;
	for (int i=1;i<=n;++i) get+=fx[i];
	cout<<get;
	for (int i=1;i<=n;++i)
		if (fx[i]) cout<<" "<<i;
	cout<<endl;
	get=0;
	for (int i=1;i<=m;++i) get+=fy[i];
	cout<<get;
	for (int i=1;i<=m;++i)
		if (fy[i]) cout<<" "<<i;
	cout<<endl;
	return 0;
}